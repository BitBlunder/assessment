/* This define (__WX_SETUP_H__) is used both to ensure setup.h is included
 * only once and to indicate that we are building using configure. */
#ifndef __WX_SETUP_H__
#define __WX_SETUP_H__

/* never undefine inline or const keywords for C++ compilation */
#ifndef __cplusplus

/* Define to empty if the keyword does not work.  */
#undef const

/* Define as __inline if that's what the C compiler calls it.  */
#undef inline

#endif /* __cplusplus */

/* the installation location prefix from configure */
#define wxINSTALL_PREFIX "C:/Program Files/wxWidgets"

/* Define if ssize_t type is available.  */
/* #undef HAVE_SSIZE_T */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define this to get extra features from GNU libc. */
#ifndef _GNU_SOURCE
/* #undef _GNU_SOURCE */
#endif

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define this if your version of GTK+ is greater than 1.2.7 */
/* #undef __WXGTK127__ */

/* Define this if your version of GTK+ is greater than 2.0 */
/* #undef __WXGTK20__ */

/* Define this if your version of GTK+ is greater than 2.10 */
/* #undef __WXGTK210__ */

/* Define this if your version of GTK+ is greater than 2.18 */
/* #undef __WXGTK218__ */

/* Define this if your version of GTK+ is greater than 2.20 */
/* #undef __WXGTK220__ */

/* Define this if your version of GTK+ is >= 3.0 */
/* #undef __WXGTK3__ */

/* Define this if your version of GTK+ is >= 3.90.0 */
/* #undef __WXGTK4__ */

/* Define this if you want to use GPE features */
/* #undef __WXGPE__ */

/* Define this if your version of Motif is greater than 2.0 */
/* #undef __WXMOTIF20__ */

/* Define this if you are using Lesstif */
/* #undef __WXLESSTIF__ */

/*
 * Define to 1 for Unix[-like] system
 */
#define wxUSE_UNIX 0

/* #undef __UNIX__ */

/* #undef __AIX__ */
/* #undef __BSD__ */
/* #undef __DARWIN__ */
/* #undef __EMX__ */
/* #undef __FREEBSD__ */
/* #undef __HPUX__ */
/* #undef __LINUX__ */
/* #undef __NETBSD__ */
/* #undef __OPENBSD__ */
/* #undef __OSF__ */
/* #undef __QNX__ */
/* #undef __SGI__ */
/* #undef __SOLARIS__ */
/* #undef __SUN__ */
/* #undef __SUNOS__ */
/* #undef __SVR4__ */
/* #undef __SYSV__ */
/* #undef __ULTRIX__ */
/* #undef __UNIXWARE__ */
/* #undef __VMS__ */

/* #undef __IA64__ */
/* #undef __ALPHA__ */

/* NanoX (with wxX11) */
#define wxUSE_NANOX 0

/* PowerPC Darwin & Mac OS X */
/* #undef __POWERPC__ */

/* Hack to make IOGraphicsTypes.h not define Point conflicting with MacTypes */
#undef __Point__

/* MS-DOS with DJGPP */
/* #undef __DOS__ */

/* Stupid hack; __WINDOWS__ clashes with wx/defs.h */
#ifndef __WINDOWS__
#define __WINDOWS__ 1
#endif

#ifndef __WIN32__
#define __WIN32__ 1
#endif
#ifndef __GNUWIN32__
/* #undef __GNUWIN32__ */
#endif
#ifndef STRICT
/* #undef STRICT */
#endif
#ifndef WINVER
/* #undef WINVER */
#endif

/* --- start common options --- */

#ifndef wxUSE_GUI
    #define wxUSE_GUI 1
#endif


#define WXWIN_COMPATIBILITY_2_8 0

#define WXWIN_COMPATIBILITY_3_0 1

#define wxDIALOG_UNIT_COMPATIBILITY 0

#define wxUSE_UNSAFE_WXSTRING_CONV 1

#define wxUSE_REPRODUCIBLE_BUILD 0



#define wxUSE_ON_FATAL_EXCEPTION 1

#define wxUSE_STACKWALKER 1

#define wxUSE_DEBUGREPORT 1



#define wxUSE_DEBUG_CONTEXT 0

#define wxUSE_MEMORY_TRACING 0

#define wxUSE_GLOBAL_MEMORY_OPERATORS 0

#define wxUSE_DEBUG_NEW_ALWAYS 0



#ifndef wxUSE_UNICODE
    #define wxUSE_UNICODE 1
#endif


#define wxUSE_EXCEPTIONS 1

#define wxUSE_EXTENDED_RTTI 0

#define wxUSE_LOG 1

#define wxUSE_LOGWINDOW 1

#define wxUSE_LOGGUI 1

#define wxUSE_LOG_DIALOG 1

#define wxUSE_CMDLINE_PARSER 1

#define wxUSE_THREADS 1

#define wxUSE_STREAMS 1

#define wxUSE_PRINTF_POS_PARAMS 1

#define wxUSE_COMPILER_TLS 1


#define wxUSE_STL 0

#define wxUSE_STD_DEFAULT 1

#define wxUSE_STD_CONTAINERS_COMPATIBLY wxUSE_STD_DEFAULT

#define wxUSE_STD_CONTAINERS 0

#define wxUSE_STD_IOSTREAM  wxUSE_STD_DEFAULT

#define wxUSE_STD_STRING  wxUSE_STD_DEFAULT

#define wxUSE_STD_STRING_CONV_IN_WXSTRING wxUSE_STL


#define wxUSE_LONGLONG 1

#define wxUSE_BASE64 1

#define wxUSE_CONSOLE_EVENTLOOP 1

#define wxUSE_FILE 1
#define wxUSE_FFILE 1

#define wxUSE_FSVOLUME 1

#define wxUSE_SECRETSTORE 1

#define wxUSE_SPELLCHECK 1

#define wxUSE_STDPATHS 1

#define wxUSE_TEXTBUFFER 1

#define wxUSE_TEXTFILE 1

#define wxUSE_INTL 1

#define wxUSE_XLOCALE 1

#define wxUSE_DATETIME 1

#define wxUSE_TIMER 1

#define wxUSE_STOPWATCH 1

#define wxUSE_FSWATCHER 1

#define wxUSE_CONFIG 1

#define wxUSE_CONFIG_NATIVE 1

#define wxUSE_DIALUP_MANAGER 1

#define wxUSE_DYNLIB_CLASS 1

#define wxUSE_DYNAMIC_LOADER 1

#define wxUSE_SOCKETS 1

#define wxUSE_IPV6 1

#define wxUSE_FILESYSTEM 1

#define wxUSE_FS_ZIP 1

#define wxUSE_FS_ARCHIVE 1

#define wxUSE_FS_INET 1

#define wxUSE_ARCHIVE_STREAMS 1

#define wxUSE_ZIPSTREAM 1

#define wxUSE_TARSTREAM 1

#define wxUSE_ZLIB 1

#define wxUSE_LIBLZMA 0

#define wxUSE_APPLE_IEEE 1

#define wxUSE_JOYSTICK 1

#define wxUSE_FONTENUM 1

#define wxUSE_FONTMAP 1

#define wxUSE_MIMETYPE 1

#define wxUSE_WEBREQUEST 1

#ifdef __APPLE__
#define wxUSE_WEBREQUEST_URLSESSION wxUSE_WEBREQUEST
#else
#define wxUSE_WEBREQUEST_URLSESSION 0
#endif

#define wxUSE_WEBREQUEST_CURL 0

#define wxUSE_PROTOCOL 1

#define wxUSE_PROTOCOL_FILE 1
#define wxUSE_PROTOCOL_FTP 1
#define wxUSE_PROTOCOL_HTTP 1

#define wxUSE_URL 1

#define wxUSE_URL_NATIVE 0

#define wxUSE_VARIANT 1

#define wxUSE_ANY 1

#define wxUSE_REGEX 1

#define wxUSE_SYSTEM_OPTIONS 1

#define wxUSE_SOUND 1

#define wxUSE_MEDIACTRL 1

#define wxUSE_XRC 1

#define wxUSE_XML 1

#define wxUSE_AUI 1

#define wxUSE_RIBBON 1

#define wxUSE_PROPGRID 1

#define wxUSE_STC 1

#define wxUSE_WEBVIEW 1

#ifdef __WXMSW__
#define wxUSE_WEBVIEW_IE 1
#else
#define wxUSE_WEBVIEW_IE 1
#endif

#define wxUSE_WEBVIEW_EDGE 0

#define wxUSE_WEBVIEW_EDGE_STATIC 0

#if (defined(__WXGTK__) && !defined(__WXGTK3__)) || defined(__WXOSX__)
#define wxUSE_WEBVIEW_WEBKIT 1
#else
#define wxUSE_WEBVIEW_WEBKIT 1
#endif

#if defined(__WXGTK3__)
#define wxUSE_WEBVIEW_WEBKIT2 0
#else
#define wxUSE_WEBVIEW_WEBKIT2 0
#endif


#if defined(_MSC_VER) || \
    (defined(__MINGW32__) && (__GNUC__ > 4 || __GNUC_MINOR__ >= 8))
#define wxUSE_GRAPHICS_CONTEXT 1
#else
#define wxUSE_GRAPHICS_CONTEXT 1
#endif

#define wxUSE_CAIRO 0



#define wxUSE_CONTROLS 1

#define wxUSE_MARKUP 1

#define wxUSE_POPUPWIN 1

#define wxUSE_TIPWINDOW 1

#define wxUSE_ACTIVITYINDICATOR 1
#define wxUSE_ANIMATIONCTRL 1
#define wxUSE_BANNERWINDOW 1
#define wxUSE_BUTTON 1
#define wxUSE_BMPBUTTON 1
#define wxUSE_CALENDARCTRL 1
#define wxUSE_CHECKBOX 1
#define wxUSE_CHECKLISTBOX 1
#define wxUSE_CHOICE 1
#define wxUSE_COLLPANE 1
#define wxUSE_COLOURPICKERCTRL 1
#define wxUSE_COMBOBOX 1
#define wxUSE_COMMANDLINKBUTTON 1
#define wxUSE_DATAVIEWCTRL 1
#define wxUSE_DATEPICKCTRL 1
#define wxUSE_DIRPICKERCTRL 1
#define wxUSE_EDITABLELISTBOX 1
#define wxUSE_FILECTRL 1
#define wxUSE_FILEPICKERCTRL 1
#define wxUSE_FONTPICKERCTRL 1
#define wxUSE_GAUGE 1
#define wxUSE_HEADERCTRL 1
#define wxUSE_HYPERLINKCTRL 1
#define wxUSE_LISTBOX 1
#define wxUSE_LISTCTRL 1
#define wxUSE_RADIOBOX 1
#define wxUSE_RADIOBTN 1
#define wxUSE_RICHMSGDLG 1
#define wxUSE_SCROLLBAR 1
#define wxUSE_SEARCHCTRL 1
#define wxUSE_SLIDER 1
#define wxUSE_SPINBTN 1
#define wxUSE_SPINCTRL 1
#define wxUSE_STATBOX 1
#define wxUSE_STATLINE 1
#define wxUSE_STATTEXT 1
#define wxUSE_STATBMP 1
#define wxUSE_TEXTCTRL 1
#define wxUSE_TIMEPICKCTRL 1
#define wxUSE_TOGGLEBTN 1
#define wxUSE_TREECTRL 1
#define wxUSE_TREELISTCTRL 1

#define wxUSE_NATIVE_DATAVIEWCTRL 1

#define wxUSE_STATUSBAR 1

#define wxUSE_NATIVE_STATUSBAR 1

#define wxUSE_TOOLBAR 1
#define wxUSE_TOOLBAR_NATIVE 1

#define wxUSE_NOTEBOOK 1

#define wxUSE_LISTBOOK 1

#define wxUSE_CHOICEBOOK 1

#define wxUSE_TREEBOOK 1

#define wxUSE_TOOLBOOK 1

#define wxUSE_TASKBARICON 1

#define wxUSE_GRID 1

#define wxUSE_MINIFRAME 1

#define wxUSE_COMBOCTRL 1

#define wxUSE_ODCOMBOBOX 1

#define wxUSE_BITMAPCOMBOBOX 1

#define wxUSE_REARRANGECTRL 1

#define wxUSE_ADDREMOVECTRL 1


#define wxUSE_ACCEL 1

#define wxUSE_ARTPROVIDER_STD 1

#define wxUSE_ARTPROVIDER_TANGO 1

#define wxUSE_HOTKEY 1

#define wxUSE_CARET 1

#define wxUSE_DISPLAY 1

#define wxUSE_GEOMETRY 1

#define wxUSE_IMAGLIST 1

#define wxUSE_INFOBAR 1

#define wxUSE_MENUS 1

#define wxUSE_MENUBAR 1

#define wxUSE_NOTIFICATION_MESSAGE 1

#define wxUSE_PREFERENCES_EDITOR 1

#define wxUSE_PRIVATE_FONTS 1

#define wxUSE_RICHTOOLTIP 1

#define wxUSE_SASH 1

#define wxUSE_SPLITTER 1

#define wxUSE_TOOLTIPS 1

#define wxUSE_VALIDATORS 1

#ifdef __WXMSW__
#define wxUSE_AUTOID_MANAGEMENT 1
#else
#define wxUSE_AUTOID_MANAGEMENT 1
#endif


#define wxUSE_COMMON_DIALOGS 1

#define wxUSE_BUSYINFO 1

#define wxUSE_CHOICEDLG 1

#define wxUSE_COLOURDLG 1

#define wxUSE_DIRDLG 1

#define wxUSE_FILEDLG 1

#define wxUSE_FINDREPLDLG 1

#define wxUSE_FONTDLG 1

#define wxUSE_MSGDLG 1

#define wxUSE_PROGRESSDLG 1

#define wxUSE_NATIVE_PROGRESSDLG 1

#define wxUSE_STARTUP_TIPS 1

#define wxUSE_TEXTDLG 1

#define wxUSE_NUMBERDLG 1

#define wxUSE_CREDENTIALDLG 1

#define wxUSE_SPLASH 1

#define wxUSE_WIZARDDLG 1

#define wxUSE_ABOUTDLG 1

#define wxUSE_FILE_HISTORY 1


#define wxUSE_METAFILE 1
#define wxUSE_ENH_METAFILE 1
#define wxUSE_WIN_METAFILES_ALWAYS 0


#define wxUSE_MDI 1

#define wxUSE_DOC_VIEW_ARCHITECTURE 1

#define wxUSE_MDI_ARCHITECTURE 1

#define wxUSE_PRINTING_ARCHITECTURE 1

#define wxUSE_HTML 1

#define wxUSE_GLCANVAS 1

#define wxUSE_GLCANVAS_EGL 0

#define wxUSE_RICHTEXT 1


#define wxUSE_CLIPBOARD 1

#define wxUSE_DATAOBJ 1

#define wxUSE_DRAG_AND_DROP 1

#ifdef __WXMSW__
#define wxUSE_ACCESSIBILITY 1
#else
#define wxUSE_ACCESSIBILITY 1
#endif


#define wxUSE_SNGLINST_CHECKER 1

#define wxUSE_DRAGIMAGE 1

#define wxUSE_IPC 1

#define wxUSE_HELP 1


#define wxUSE_MS_HTML_HELP 1


#define wxUSE_WXHTML_HELP 1

#define wxUSE_CONSTRAINTS 1


#define wxUSE_SPLINES 1


#define wxUSE_MOUSEWHEEL 1


#define wxUSE_UIACTIONSIMULATOR 1


#define wxUSE_POSTSCRIPT 1

#define wxUSE_AFM_FOR_POSTSCRIPT 1

#define wxUSE_SVG 1

#define wxUSE_DC_TRANSFORM_MATRIX 1


#define wxUSE_IMAGE 1

#define wxUSE_LIBPNG 1

#define wxUSE_LIBJPEG 1

#define wxUSE_LIBTIFF 1

#define wxUSE_NANOSVG 1

#define wxUSE_NANOSVG_EXTERNAL 0

#define wxUSE_TGA 1

#define wxUSE_GIF 1

#define wxUSE_PNM 1

#define wxUSE_PCX 1

#define wxUSE_IFF 1

#define wxUSE_XPM 1

#define wxUSE_ICO_CUR 1

#define wxUSE_PALETTE 1


#define wxUSE_ALL_THEMES 0

#define wxUSE_THEME_GTK 0
#define wxUSE_THEME_METAL 0
#define wxUSE_THEME_MONO 0
#define wxUSE_THEME_WIN32 0

/* --- end common options --- */

/*
 * Unix-specific options
 */
#define wxUSE_SELECT_DISPATCHER 0
#define wxUSE_EPOLL_DISPATCHER 0

#define wxUSE_UNICODE_UTF8 0
#define wxUSE_UTF8_LOCALE_ONLY 0

/*
   Use GStreamer for Unix.

   Default is 0 as this requires a lot of dependencies which might not be
   available.

   Recommended setting: 1 (wxMediaCtrl won't work by default without it).
 */
#define wxUSE_GSTREAMER 0

#define wxUSE_GSTREAMER_PLAYER 0

/*
   Use XTest extension to implement wxUIActionSimulator?

   Default is 1, it is set to 0 if the necessary headers/libraries are not
   found by configure.

   Recommended setting: 1, wxUIActionSimulator won't work in wxGTK3 without it.
 */
#define wxUSE_XTEST 0

/* --- start MSW options --- */


#define wxUSE_GRAPHICS_GDIPLUS wxUSE_GRAPHICS_CONTEXT

#if defined(_MSC_VER) && _MSC_VER >= 1600
    #define wxUSE_GRAPHICS_DIRECT2D wxUSE_GRAPHICS_CONTEXT
#else
    #define wxUSE_GRAPHICS_DIRECT2D 1
#endif

#define wxUSE_WEBREQUEST_WINHTTP 1


#define wxUSE_OLE 1

#define wxUSE_OLE_AUTOMATION 1

#define wxUSE_ACTIVEX 1

#if defined(_MSC_VER) && _MSC_VER >= 1700 && !defined(_USING_V110_SDK71_)
    #define wxUSE_WINRT 1
#else
    #define wxUSE_WINRT 1
#endif

#define wxUSE_DC_CACHEING 1

#define wxUSE_WXDIB 1

#define wxUSE_POSTSCRIPT_ARCHITECTURE_IN_MSW 1

#define wxUSE_REGKEY 1

#define wxUSE_RICHEDIT 1

#define wxUSE_RICHEDIT2 1

#define wxUSE_OWNER_DRAWN 1

#define wxUSE_TASKBARICON_BALLOONS 1

#define wxUSE_TASKBARBUTTON 1

#define wxUSE_UXTHEME 1

#define wxUSE_INKEDIT 0

#define wxUSE_INICONF 1

#define wxUSE_WINSOCK2 0


#define wxUSE_DATEPICKCTRL_GENERIC 0

#define wxUSE_TIMEPICKCTRL_GENERIC 0


#if defined(__VISUALC__) || defined(__MINGW64_TOOLCHAIN__)
    #define wxUSE_DBGHELP 1
#else
    #define wxUSE_DBGHELP 1
#endif

#define wxUSE_CRASHREPORT 1
/* --- end MSW options --- */

/*
 * Define if your compiler has C99 va_copy
 */
/* #undef HAVE_VA_COPY */

/*
 * Define if va_list type is an array
 */
/* #undef VA_LIST_IS_ARRAY */

/*
 * Define if you don't want variadic macros to be used even if they are
 * supported by the compiler.
 */
/* #undef wxNO_VARIADIC_MACROS */

/*
 * Define if your compiler has std::wstring
 */
#define HAVE_STD_WSTRING 1
/*
 * Define if your compiler has compliant std::string::compare
 */
#define HAVE_STD_STRING_COMPARE 1
/*
 * Define if your compiler has <hash_map>
 */
/* #undef HAVE_HASH_MAP */
/*
 * Define if your compiler has <ext/hash_map>
 */
/* #undef HAVE_EXT_HASH_MAP */
/*
 * Define if your compiler has std::hash_map/hash_set
 */
/* #undef HAVE_STD_HASH_MAP */
/*
 * Define if your compiler has __gnu_cxx::hash_map/hash_set
 */
/* #undef HAVE_GNU_CXX_HASH_MAP */

/*
 * Define if your compiler has std::unordered_map
 */
#define HAVE_STD_UNORDERED_MAP 1

/*
 * Define if your compiler has std::unordered_set
 */
#define HAVE_STD_UNORDERED_SET 1

/*
 * Define if your compiler has std::tr1::unordered_map
 */
/* #undef HAVE_TR1_UNORDERED_MAP */

/*
 * Define if your compiler has std::tr1::unordered_set
 */
/* #undef HAVE_TR1_UNORDERED_SET */

/*
 * Define if your compiler has <tr1/type_traits>
 */
/* #undef HAVE_TR1_TYPE_TRAITS */

/*
 * Define if your compiler has <type_traits>
 */
#define HAVE_TYPE_TRAITS 1

/*
 * Define if the compiler supports simple visibility declarations.
 */
/* #undef HAVE_VISIBILITY */

/*
 * Define if the compiler supports GCC's atomic memory access builtins
 */
/* #undef HAVE_GCC_ATOMIC_BUILTINS */

/*
 * Define if compiler's visibility support in libstdc++ is broken
 */
/* #undef HAVE_BROKEN_LIBSTDCXX_VISIBILITY */

/*
 * On GNU systems use re_search instead of regexec, since the latter does a
 * strlen on the search text affecting the performance of some operations.
 */
/* #undef HAVE_RE_SEARCH */
/*
 * Use SDL for audio (Unix)
 */
#define wxUSE_LIBSDL 0

/*
 * Compile sound backends as plugins
 */
#define wxUSE_PLUGINS 0

/*
 * Use GTK print for printing under GTK+ 2.10+
 */
#define wxUSE_GTKPRINT 0
/*
 * Use GNOME VFS for MIME types
 */
#define wxUSE_LIBGNOMEVFS 0
/*
 * Use libnotify library.
 */
#define wxUSE_LIBNOTIFY 0
/*
 * Use libnotify 0.7+ API.
 */
#define wxUSE_LIBNOTIFY_0_7 0
/*
 * Use libXpm
 */
#define wxHAVE_LIB_XPM 0
/*
 * Define if you have pthread_cleanup_push/pop()
 */
/* #undef wxHAVE_PTHREAD_CLEANUP */
/*
 * Define if compiler has __thread keyword.
 */
/* #undef HAVE___THREAD_KEYWORD */
/*
 * Define if large (64 bit file offsets) files are supported.
 */
/* #undef HAVE_LARGEFILE_SUPPORT */

/*
 * Use OpenGL
 */
#define wxUSE_OPENGL 1

/*
 * Use MS HTML Help via libmspack (Unix)
 */
#define wxUSE_LIBMSPACK 0

/*
 * Matthews garbage collection (used for MrEd?)
 */
#define WXGARBAGE_COLLECTION_ON 0

/*
 * wxWebKitCtrl
 */
#define wxUSE_WEBKIT 0

/*
 * The const keyword is being introduced more in wxWindows.
 * You can use this setting to maintain backward compatibility.
 * If 0: will use const wherever possible.
 * If 1: will use const only where necessary
 *       for precompiled headers to work.
 * If 2: will be totally backward compatible, but precompiled
 *       headers may not work and program size will be larger.
 */
#define CONST_COMPATIBILITY 0

/*
 * use the session manager to detect KDE/GNOME
 */
#define wxUSE_DETECT_SM 0


/* define with the name of timezone variable */
#define WX_TIMEZONE _timezone

/* The type of 3rd argument to getsockname() - usually size_t or int */
/* #undef WX_SOCKLEN_T */

/* The type of 5th argument to getsockopt() - usually size_t or int */
/* #undef SOCKOPTLEN_T */

/* The type of statvfs(2) argument */
/* #undef WX_STATFS_T */

/* The signal handler prototype */
#define wxTYPE_SA_HANDLER 

/* gettimeofday() usually takes 2 arguments, but some really old systems might
 * have only one, in which case define WX_GETTIMEOFDAY_NO_TZ */
/* #undef WX_GETTIMEOFDAY_NO_TZ */

/* struct tm doesn't always have the tm_gmtoff field, define this if it does */
/* #undef WX_GMTOFF_IN_TM */

/* check if nl_langinfo() can be called with argument _NL_TIME_FIRST_WEEKDAY */
/* #undef HAVE_NL_TIME_FIRST_WEEKDAY */

/* Define if you have poll(2) function */
/* #undef HAVE_POLL */

/* Define if you have pw_gecos field in struct passwd */
/* #undef HAVE_PW_GECOS */

/* Define if you have __cxa_demangle() in <cxxabi.h> */
/* #undef HAVE_CXA_DEMANGLE */

/* Define if you have dlopen() */
/* #undef HAVE_DLOPEN */

/* Define if you have gettimeofday() */
/* #undef HAVE_GETTIMEOFDAY */

/* Define if fsync() is available */
/* #undef HAVE_FSYNC */

/* Define if round() is available */
#define HAVE_ROUND 1

/* Define if you have ftime() */
/* #undef HAVE_FTIME */

/* Define if you have nanosleep() */
/* #undef HAVE_NANOSLEEP */

/* Define if you have sched_yield */
/* #undef HAVE_SCHED_YIELD */

/* Define if you have pthread_mutexattr_t and functions to work with it */
/* #undef HAVE_PTHREAD_MUTEXATTR_T */

/* Define if you have pthread_mutexattr_settype() declaration */
/* #undef HAVE_PTHREAD_MUTEXATTR_SETTYPE_DECL */

/* Define if you have PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP */
/* #undef HAVE_PTHREAD_RECURSIVE_MUTEX_INITIALIZER */

/* Define if you have pthread_cancel */
/* #undef HAVE_PTHREAD_CANCEL */

/* Define if you have pthread_mutex_timedlock */
/* #undef HAVE_PTHREAD_MUTEX_TIMEDLOCK */

/* Define if you have pthread_attr_setstacksize */
/* #undef HAVE_PTHREAD_ATTR_SETSTACKSIZE */

/* Define if you have snprintf() */
/* #undef HAVE_SNPRINTF */

/* Define if you have a snprintf() which supports positional arguments
   (defined in the unix98 standard) */
/* #undef HAVE_UNIX98_PRINTF */

/* define if you have statfs function */
/* #undef HAVE_STATFS */

/* define if you have statfs prototype */
/* #undef HAVE_STATFS_DECL */

/* define if you have statvfs function */
/* #undef HAVE_STATVFS */

/* Define if you have strtoull() and strtoll() */
#define HAVE_STRTOULL 1

/* Define if you have all functions to set thread priority */
/* #undef HAVE_THREAD_PRIORITY_FUNCTIONS */

/* Define if you have vsnprintf() */
/* #undef HAVE_VSNPRINTF */

/* Define if you have a _broken_ vsnprintf() declaration in the header,
 * with 'char*' for the 3rd parameter instead of 'const char*' */
/* #undef HAVE_BROKEN_VSNPRINTF_DECL */

/* Define if you have a _broken_ vsscanf() declaration in the header,
 * with 'char*' for the 1st parameter instead of 'const char*' */
/* #undef HAVE_BROKEN_VSSCANF_DECL */

/* Define if you have vsscanf() */
#define HAVE_VSSCANF 1

/* Define if you have usleep() */
/* #undef HAVE_USLEEP */

/* Define if you have wcscasecmp() function  */
/* #undef HAVE_WCSCASECMP */

/* Define if you have wcsncasecmp() function  */
/* #undef HAVE_WCSNCASECMP */

/* Define if you have wcslen function  */
#define HAVE_WCSLEN 1

/* Define if you have wcsdup function  */
#define HAVE_WCSDUP 1

/* Define if you have wcsftime() function  */
#define HAVE_WCSFTIME 1

/* Define if you have strnlen() function */
#define HAVE_STRNLEN 1

/* Define if you have wcsnlen() function */
#define HAVE_WCSNLEN 1

/* Define if you have wcstoull() and wcstoll() */
#define HAVE_WCSTOULL 1

/* The number of bytes in a wchar_t.  */
#define SIZEOF_WCHAR_T 2

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* The number of bytes in a pointer.  */
#define SIZEOF_VOID_P 8

/* The number of bytes in a long.  */
#define SIZEOF_LONG 4

/* The number of bytes in a long long.  */
#define SIZEOF_LONG_LONG 8

/* The number of bytes in a short.  */
#define SIZEOF_SHORT 2

/* The number of bytes in a size_t.  */
#define SIZEOF_SIZE_T 8

/* Define if size_t on your machine is the same type as unsigned int. */
/* #undef wxSIZE_T_IS_UINT */

/* Define if size_t on your machine is the same type as unsigned long. */
/* #undef wxSIZE_T_IS_ULONG */

/* Define if wchar_t is distinct type in your compiler. */
#define wxWCHAR_T_IS_REAL_TYPE 1

/* Define if you have the dladdr function.  */
/* #undef HAVE_DLADDR */

/* Define if you have Posix fnctl() function. */
/* #undef HAVE_FCNTL */

/* Define if you have BSD flock() function. */
/* #undef HAVE_FLOCK */

/* Define if you have getaddrinfo function. */
/* #undef HAVE_GETADDRINFO */

/* Define if you have a gethostbyname_r function taking 6 arguments. */
/* #undef HAVE_FUNC_GETHOSTBYNAME_R_6 */

/* Define if you have a gethostbyname_r function taking 5 arguments. */
/* #undef HAVE_FUNC_GETHOSTBYNAME_R_5 */

/* Define if you have a gethostbyname_r function taking 3 arguments. */
/* #undef HAVE_FUNC_GETHOSTBYNAME_R_3 */

/* Define if you only have a gethostbyname function */
/* #undef HAVE_GETHOSTBYNAME */

/* Define if you have the gethostname function.  */
/* #undef HAVE_GETHOSTNAME */

/* Define if you have a getservbyname_r function taking 6 arguments. */
/* #undef HAVE_FUNC_GETSERVBYNAME_R_6 */

/* Define if you have a getservbyname_r function taking 5 arguments. */
/* #undef HAVE_FUNC_GETSERVBYNAME_R_5 */

/* Define if you have a getservbyname_r function taking 4 arguments. */
/* #undef HAVE_FUNC_GETSERVBYNAME_R_4 */

/* Define if you only have a getservbyname function */
/* #undef HAVE_GETSERVBYNAME */

/* Define if you have the gmtime_r function.  */
/* #undef HAVE_GMTIME_R */

/* Define if you have the inet_addr function.  */
/* #undef HAVE_INET_ADDR */

/* Define if you have the inet_aton function.  */
/* #undef HAVE_INET_ATON */

/* Define if you have the localtime_r function.  */
/* #undef HAVE_LOCALTIME_R */

/* Define if you have the mktemp function.  */
/* #undef HAVE_MKTEMP */

/* Define if you have the mkstemp function.  */
/* #undef HAVE_MKSTEMP */

/* Define if you have the putenv function.  */
/* #undef HAVE_PUTENV */

/* Define if you have the setenv function.  */
/* #undef HAVE_SETENV */

/* Define if you have strtok_r function. */
/* #undef HAVE_STRTOK_R */

/* Define if you have thr_setconcurrency function */
/* #undef HAVE_THR_SETCONCURRENCY */

/* Define if you have pthread_setconcurrency function */
/* #undef HAVE_PTHREAD_SET_CONCURRENCY */

/* Define if you have the uname function.  */
/* #undef HAVE_UNAME */

/* Define if you have the unsetenv function.  */
/* #undef HAVE_UNSETENV */

/* Define if you have the <X11/XKBlib.h> header file.  */
/* #undef HAVE_X11_XKBLIB_H */

/* Define if you have the <X11/extensions/xf86vmode.h> header file.  */
/* #undef HAVE_X11_EXTENSIONS_XF86VMODE_H */

/* Define if you have the <sched.h> header file.  */
/* #undef HAVE_SCHED_H */

/* Define if you have the <unistd.h> header file.  */
/* #undef HAVE_UNISTD_H */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <wchar.h> header file.  */
#define HAVE_WCHAR_H 1

/* Define if you have the <wcstr.h> header file.  */
/* #undef HAVE_WCSTR_H */

/* Define if you have <widec.h> (Solaris only) */
/* #undef HAVE_WIDEC_H */

/* Define if you have the <iconv.h> header file and iconv() symbol.  */
/* #undef HAVE_ICONV */

/* Define as "const" if the declaration of iconv() needs const.  */
/* #undef ICONV_CONST */

/* Define if you have the <langinfo.h> header file.  */
/* #undef HAVE_LANGINFO_H */

/* Define if you have the <sys/soundcard.h> header file. */
/* #undef HAVE_SYS_SOUNDCARD_H */

/* Define if you have wcsrtombs() function */
/* #undef HAVE_WCSRTOMBS */

/* Define this if you have putws() */
/* #undef HAVE_PUTWS */

/* Define this if you have fputws() */
#define HAVE_FPUTWS 1

/* Define this if you have wprintf() and related functions */
#define HAVE_WPRINTF 1

/* Define this if you have vswprintf() and related functions */
#define HAVE_VSWPRINTF 1

/* Define this if you have _vsnwprintf */
/* #undef HAVE__VSNWPRINTF */

/* vswscanf() */
#define HAVE_VSWSCANF 1

/* Define if fseeko and ftello are available.  */
/* #undef HAVE_FSEEKO */

/* Define this if you are using gtk and gdk contains support for X11R6 XIM */
/* #undef HAVE_XIM */

/* Define this if you have X11/extensions/shape.h */
/* #undef HAVE_XSHAPE */

/* Define this if you have type SPBCDATA */
/* #undef HAVE_SPBCDATA */

/* Define if you have pango_font_family_is_monospace() (Pango >= 1.3.3) */
/* #undef HAVE_PANGO_FONT_FAMILY_IS_MONOSPACE */

/* Define if you have Pango xft support */
/* #undef HAVE_PANGO_XFT */

/* Define if you have the <sys/select.h> header file.  */
/* #undef HAVE_SYS_SELECT_H */

/* Define if you have abi::__forced_unwind in your <cxxabi.h>. */
/* #undef HAVE_ABI_FORCEDUNWIND */

/* Define if fdopen is available.  */
/* #undef HAVE_FDOPEN */

/* Define if sysconf is available. */
/* #undef HAVE_SYSCONF */

/* Define if getpwuid_r is available. */
/* #undef HAVE_GETPWUID_R */

/* Define if getgrgid_r is available. */
/* #undef HAVE_GETGRGID_R */

/* Define if setpriority() is available. */
/* #undef HAVE_SETPRIORITY */

/* Define if xkbcommon is available */
/* #undef HAVE_XKBCOMMON */

/* Define if xlocale.h header file exists. */
/* #undef HAVE_XLOCALE_H */

/* Define if locale_t is available */
/* #undef HAVE_LOCALE_T */

/* Define if you have inotify_xxx() functions. */
/* #undef wxHAS_INOTIFY */

/* Define if you have kqueu_xxx() functions. */
/* #undef wxHAS_KQUEUE */

/* -------------------------------------------------------------------------
   Win32 adjustments section
   ------------------------------------------------------------------------- */

#ifdef __WIN32__

/* When using an external jpeg library and the Windows headers already define
 * boolean, define to the type used by the jpeg library for boolean.  */
/* #undef wxHACK_BOOLEAN */

/* Define if the header pbt.h is missing.  */
/* #undef NEED_PBT_H */

#endif /* __WIN32__ */

/* --------------------------------------------------------*
 *  This stuff is static, it doesn't get modified directly
 *  by configure.
*/

/*
   define some constants identifying wxWindows version in more details than
   just the version number
 */

/* wxLogChain class available */
/* #undef wxHAS_LOG_CHAIN */

/* define this when wxDC::Blit() respects SetDeviceOrigin() in wxGTK */
/* #undef wxHAS_WORKING_GTK_DC_BLIT */

#endif /* __WX_SETUP_H__ */

