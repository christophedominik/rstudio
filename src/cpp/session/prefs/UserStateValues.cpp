/* UserPrefValues.cpp
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
 
/* DO NOT HAND-EDIT! This file is automatically generated from the formal user preference schema
 * JSON. To add a preference, add it to "user-prefs-schema.json", then run "generate-prefs.R" to
 * rebuild this file.
 */

#include <session/prefs/UserStateValues.hpp>

namespace rstudio {
namespace session {
namespace prefs {

/**
 * A unique identifier representing the user and machine.
 */
std::string UserStateValues::contextId()
{
   return readPref<std::string>("context_id");
}

core::Error UserStateValues::setContextId(std::string val)
{
   return writePref("context_id", val);
}

/**
 * Whether we have automatically created an .Rprofile for this user.
 */
bool UserStateValues::autoCreatedProfile()
{
   return readPref<bool>("auto_created_profile");
}

core::Error UserStateValues::setAutoCreatedProfile(bool val)
{
   return writePref("auto_created_profile", val);
}

/**
 * The color theme to apply.
 */
core::json::Object UserStateValues::theme()
{
   return readPref<core::json::Object>("theme");
}

core::Error UserStateValues::setTheme(core::json::Object val)
{
   return writePref("theme", val);
}

/**
 * The directory path under which to place new projects by default. Shadows a uipref.
 */
std::string UserStateValues::defaultProjectLocation()
{
   return readPref<std::string>("default_project_location");
}

core::Error UserStateValues::setDefaultProjectLocation(std::string val)
{
   return writePref("default_project_location", val);
}

/**
 * Whether to clear hidden objects along with visible objects when clearing the workspace. Set automatically to remember last action.
 */
bool UserStateValues::clearHidden()
{
   return readPref<bool>("clear_hidden");
}

core::Error UserStateValues::setClearHidden(bool val)
{
   return writePref("clear_hidden", val);
}

/**
 * The most recently used plot export options.
 */
core::json::Object UserStateValues::exportPlotOptions()
{
   return readPref<core::json::Object>("export_plot_options");
}

core::Error UserStateValues::setExportPlotOptions(core::json::Object val)
{
   return writePref("export_plot_options", val);
}

/**
 * The most recently used viewer export options.
 */
core::json::Object UserStateValues::exportViewerOptions()
{
   return readPref<core::json::Object>("export_viewer_options");
}

core::Error UserStateValues::setExportViewerOptions(core::json::Object val)
{
   return writePref("export_viewer_options", val);
}

/**
 * The most recently used options for saving a plot as a PDF.
 */
core::json::Object UserStateValues::savePlotAsPdfOptions()
{
   return readPref<core::json::Object>("save_plot_as_pdf_options");
}

core::Error UserStateValues::setSavePlotAsPdfOptions(core::json::Object val)
{
   return writePref("save_plot_as_pdf_options", val);
}

/**
 * Most recently used settings for compiling a notebook from an R script.
 */
core::json::Object UserStateValues::compileRNotebookPrefs()
{
   return readPref<core::json::Object>("compile_r_notebook_prefs");
}

core::Error UserStateValues::setCompileRNotebookPrefs(core::json::Object val)
{
   return writePref("compile_r_notebook_prefs", val);
}

/**
 * Most recently used settings for compiling a notebook using R Markdown.
 */
core::json::Object UserStateValues::compileRMarkdownNotebookPrefs()
{
   return readPref<core::json::Object>("compile_r_markdown_notebook_prefs");
}

core::Error UserStateValues::setCompileRMarkdownNotebookPrefs(core::json::Object val)
{
   return writePref("compile_r_markdown_notebook_prefs", val);
}

/**
 * Whether to show UI for publishing content.
 */
bool UserStateValues::showPublishUi()
{
   return readPref<bool>("show_publish_ui");
}

core::Error UserStateValues::setShowPublishUi(bool val)
{
   return writePref("show_publish_ui", val);
}

/**
 * Whether to show UI for publishing content to RStudio Connect.
 */
bool UserStateValues::enableRsconnectPublishUi()
{
   return readPref<bool>("enable_rsconnect_publish_ui");
}

core::Error UserStateValues::setEnableRsconnectPublishUi(bool val)
{
   return writePref("enable_rsconnect_publish_ui", val);
}

/**
 * The default (last) account used for publishing
 */
core::json::Object UserStateValues::publishAccount()
{
   return readPref<core::json::Object>("publish_account");
}

core::Error UserStateValues::setPublishAccount(core::json::Object val)
{
   return writePref("publish_account", val);
}

/**
 * The preferred width, in pixels, of the document outline pane.
 */
int UserStateValues::documentOutlineWidth()
{
   return readPref<int>("document_outline_width");
}

core::Error UserStateValues::setDocumentOutlineWidth(int val)
{
   return writePref("document_outline_width", val);
}

/**
 * How to create new connections to data sources.
 */
std::string UserStateValues::connectVia()
{
   return readPref<std::string>("connect_via");
}

core::Error UserStateValues::setConnectVia(std::string val)
{
   return writePref("connect_via", val);
}

/**
 * The kind of handler to invoke when errors occur.
 */
std::string UserStateValues::errorHandlerType()
{
   return readPref<std::string>("error_handler_type");
}

core::Error UserStateValues::setErrorHandlerType(std::string val)
{
   return writePref("error_handler_type", val);
}

/**
 * Whether or not the MinGW compiler with GCC 4.9 is used.
 */
bool UserStateValues::usingMingwGcc49()
{
   return readPref<bool>("using_mingw_gcc49");
}

core::Error UserStateValues::setUsingMingwGcc49(bool val)
{
   return writePref("using_mingw_gcc49", val);
}

/**
 * Whether or not the use of Visual Mode has been confirmed.
 */
bool UserStateValues::visualModeConfirmed()
{
   return readPref<bool>("visual_mode_confirmed");
}

core::Error UserStateValues::setVisualModeConfirmed(bool val)
{
   return writePref("visual_mode_confirmed", val);
}

/**
 * The default type for new bibliographies.
 */
std::string UserStateValues::bibliographyDefaultType()
{
   return readPref<std::string>("bibliography_default_type");
}

core::Error UserStateValues::setBibliographyDefaultType(std::string val)
{
   return writePref("bibliography_default_type", val);
}

/**
 * Zotero connection type (local or web)
 */
std::string UserStateValues::zoteroConnectionType()
{
   return readPref<std::string>("zotero_connection_type");
}

core::Error UserStateValues::setZoteroConnectionType(std::string val)
{
   return writePref("zotero_connection_type", val);
}

/**
 * Zotero libraries to insert citations from.
 */
core::json::Array UserStateValues::zoteroLibraries()
{
   return readPref<core::json::Array>("zotero_libraries");
}

core::Error UserStateValues::setZoteroLibraries(core::json::Array val)
{
   return writePref("zotero_libraries", val);
}

/**
 * Whether to use Better BibTeX when suggesting citation keys and writing citations to BibLaTeX bibliographies
 */
bool UserStateValues::zoteroUseBetterBibtex()
{
   return readPref<bool>("zotero_use_better_bibtex");
}

core::Error UserStateValues::setZoteroUseBetterBibtex(bool val)
{
   return writePref("zotero_use_better_bibtex", val);
}

/**
 * Key for making Zotero API calls
 */
std::string UserStateValues::zoteroApiKey()
{
   return readPref<std::string>("zotero_api_key");
}

core::Error UserStateValues::setZoteroApiKey(std::string val)
{
   return writePref("zotero_api_key", val);
}

/**
 * Directory containing Zotero data files
 */
std::string UserStateValues::zoteroDataDir()
{
   return readPref<std::string>("zotero_data_dir");
}

core::Error UserStateValues::setZoteroDataDir(std::string val)
{
   return writePref("zotero_data_dir", val);
}

std::vector<std::string> UserStateValues::allKeys()
{
   return std::vector<std::string>({
      kContextId,
      kAutoCreatedProfile,
      kTheme,
      kDefaultProjectLocation,
      kClearHidden,
      kExportPlotOptions,
      kExportViewerOptions,
      kSavePlotAsPdfOptions,
      kCompileRNotebookPrefs,
      kCompileRMarkdownNotebookPrefs,
      kShowPublishUi,
      kEnableRsconnectPublishUi,
      kPublishAccount,
      kDocumentOutlineWidth,
      kConnectVia,
      kErrorHandlerType,
      kUsingMingwGcc49,
      kVisualModeConfirmed,
      kBibliographyDefaultType,
      kZoteroConnectionType,
      kZoteroLibraries,
      kZoteroUseBetterBibtex,
      kZoteroApiKey,
      kZoteroDataDir,
   });
}
   

}
}
}
