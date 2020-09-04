/*
 * ZoteroLibrariesWidget.java
 *
 * Copyright (C) 2020 by RStudio, PBC
 *
 * Unless you have received this program directly from RStudio pursuant
 * to the terms of a commercial license agreement with RStudio, then
 * this program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */
package org.rstudio.studio.client.workbench.prefs.views.zotero;

import java.util.ArrayList;

import org.rstudio.core.client.JsArrayUtil;
import org.rstudio.core.client.StringUtil;
import org.rstudio.core.client.widget.CheckBoxList;
import org.rstudio.core.client.widget.SelectWidget;
import org.rstudio.studio.client.common.SimpleRequestCallback;
import org.rstudio.studio.client.panmirror.server.PanmirrorZoteroCollectionSpec;
import org.rstudio.studio.client.panmirror.server.PanmirrorZoteroResult;
import org.rstudio.studio.client.panmirror.server.PanmirrorZoteroServerOperations;

import com.google.gwt.aria.client.Id;
import com.google.gwt.aria.client.Roles;
import com.google.gwt.core.client.JavaScriptObject;
import com.google.gwt.core.client.JsArray;
import com.google.gwt.core.client.JsArrayString;
import com.google.gwt.user.client.ui.CheckBox;
import com.google.gwt.user.client.ui.Composite;
import com.google.gwt.user.client.ui.VerticalPanel;

public class ZoteroLibrariesWidget extends Composite
{
   public ZoteroLibrariesWidget(PanmirrorZoteroServerOperations server)
   {
      this(server, false);
   }
   
   public ZoteroLibrariesWidget(PanmirrorZoteroServerOperations server, boolean includeUseDefault)
   {
      server_ = server;
      
      VerticalPanel panel = new VerticalPanel();
      panel.addStyleName(RES.styles().librariesWidget());
      
      ArrayList<String> options = new ArrayList<String>();
      
      if (includeUseDefault)
         options.add(USE_DEFAULT);
      options.add(MY_LIBRARY);
      options.add(ALL_LIBRARIES);
      options.add(SELECTED_LIBRARIES);

      selectedLibs_ = new SelectWidget(
         "Use libraries:", 
         options.toArray(new String[] {}),
         options.toArray(new String[] {}),
         false,
         true,
         false
      );
      selectedLibs_.addStyleName(RES.styles().librariesSelect());
      panel.add(selectedLibs_);   
        
      libraries_ = new CheckBoxList(selectedLibs_.getLabel());
      libraries_.addStyleName(RES.styles().librariesList());
      panel.add(libraries_);
   
      Roles.getListboxRole().setAriaLabelledbyProperty(libraries_.getElement(),
            Id.of(selectedLibs_.getLabel().getElement()));
      
      manageUI();
      selectedLibs_.addChangeHandler((value) -> {
         manageUI();
      });
        
      initWidget(panel);
   }
   
   public void setMyLibrary()
   {
      selectedLibs_.setValue(MY_LIBRARY);
   }
   
   public void setLibraries(JsArrayString libraries)
   {
      ArrayList<String> selectedLibraries = new ArrayList<String>();
      if (libraries != null)
      {
         // set select widget based on whether we have a library whitelist
         if (libraries.length() == 0)
            selectedLibs_.setValue(ALL_LIBRARIES);
         else if (libraries.length() == 1 && libraries.get(0).equals(MY_LIBRARY))
            selectedLibs_.setValue(MY_LIBRARY);
         else
            selectedLibs_.setValue(SELECTED_LIBRARIES);
         
         // popupulate selected libraries
         for (int i = 0; i<libraries.length(); i++)
         {
            String library = libraries.get(i);
            selectedLibraries.add(library);
            CheckBox chkLibrary = new CheckBox(library);
            chkLibrary.setValue(true);
            libraries_.addItem(chkLibrary);
         }
      }
      else
      {
         selectedLibs_.setValue(USE_DEFAULT);
      }
      
      // manage visibility of selectedLibs_
      manageUI();
   }
   
   public JsArrayString getLibraries()
   {   
      JsArrayString libraries = JsArrayString.createArray().cast();
      switch(selectedLibs_.getValue())
      {
      case USE_DEFAULT:
         libraries = null;
         break;
      case MY_LIBRARY:
         libraries.push(MY_LIBRARY); 
         break;
      case ALL_LIBRARIES:
         // empty array == all libs
         break;
      case SELECTED_LIBRARIES:
         for (int i = 0; i<libraries_.getItemCount(); i++)
         {
            CheckBox chkLibrary = libraries_.getItemAtIdx(i);
            if (chkLibrary.getValue())
               libraries.push(chkLibrary.getText());
         }
      }
      return libraries;
   }
   
   public void addAvailableLibraries()
   {
      server_.zoteroGetCollectionSpecs(new SimpleRequestCallback<JavaScriptObject>() {
         @Override
         public void onResponseReceived(JavaScriptObject response)
         {     
            PanmirrorZoteroResult result = response.cast();
            if (result.getStatus().equals("ok"))
            {
               // get specs
               JsArray<PanmirrorZoteroCollectionSpec> specsJs = result.getMessage().cast();
               ArrayList<PanmirrorZoteroCollectionSpec> specs = JsArrayUtil.toArrayList(specsJs);
               
               // order by name
               specs.sort((PanmirrorZoteroCollectionSpec a, PanmirrorZoteroCollectionSpec b) -> {
                  return a.getName().compareTo(b.getName());
               });
               
               // display
               for (int i = 0; i<specs.size(); i++)
               {
                  PanmirrorZoteroCollectionSpec spec = specs.get(i);
                  if (StringUtil.isNullOrEmpty(spec.getParentKey()))
                  {
                     String name = specs.get(i).getName();
                     
                     if (!libraries_.contains(name))
                     {
                        CheckBox chkLibrary = new CheckBox(name);
                        libraries_.addItem(chkLibrary);
                     }
                  }
               }
            }
           
         }
      });
   }
   
   private void manageUI()
   {
      libraries_.setVisible(selectedLibs_.getValue().equals(SELECTED_LIBRARIES));
   }
   
   private static ZoteroResources RES = ZoteroResources.INSTANCE;
   
   
   private final static String USE_DEFAULT = "(Default)";
   private final static String MY_LIBRARY = "My Library";
   private final static String ALL_LIBRARIES = "All Libraries";
   private final static String SELECTED_LIBRARIES = "Selected Libraries";
   
   private final SelectWidget selectedLibs_;
   private final CheckBoxList libraries_;
   
   private final PanmirrorZoteroServerOperations server_;
   
}
