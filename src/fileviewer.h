/*
 *  This file is part of poEdit (http://www.poedit.org)
 *
 *  Copyright (C) 1999-2005 Vaclav Slavik
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 *
 *  $Id$
 *
 *  Shows part of file around specified line
 *
 */

#ifndef _FILEVIEWER_H_
#define _FILEVIEWER_H_

#include <wx/frame.h>
class WXDLLEXPORT wxListCtrl;


/** This class implements frame that shows part of file
    surrounding specified line (40 lines in both directions).
 */
class FileViewer : public wxFrame
{
    public:
        /** Ctor. 
            \param basePath   base directory that all entries in 
                              \i references are relative to
            \param references array of strings in format \i filename:linenum
                              that lists all occurences of given string
            \param openAt     number of the \i references entry to show
                              by default
         */
        FileViewer(wxWindow *parent, const wxString& basePath,
                   const wxArrayString& references, size_t openAt);
        ~FileViewer();
        
        /// Shows given reference, i.e. loads the file
        void ShowReference(const wxString& ref);
        
        /// Open file in an editor
        static void OpenInEditor(const wxString& basepath, 
                                 const wxString& reference);

        bool FileOk() { return !m_current.empty(); }
        
    private:
        wxString m_basePath;
        wxArrayString m_references;
        wxString m_current;
        
        wxListCtrl *m_list;
    
        void OnChoice(wxCommandEvent &event);
        void OnEditFile(wxCommandEvent &event);
        DECLARE_EVENT_TABLE();
};



#endif // _FILEVIEWER_H_