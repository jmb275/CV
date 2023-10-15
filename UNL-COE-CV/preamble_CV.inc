% Hey, Emacs! This is a -*- LaTeX -*- file!

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
% 
% Author: Justin Bradley
% Title: preamble_CV.inc
% Date: Thursday, October 22, 2020
% Description: Header for Curriculum Vitae for COE at UNL
%
% Changes:
% 2020-10: Add nice comments and instructions for others to use the template
% 2023-01:
%    * Added support for reverse ordering journals, conferences,
%      grants, and books.
%    * Added support for listing books
%    * Cleaned up preamble_CV.inc and added better documentation throughout
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

%%%%%%%%%%%%%%%%%%%%%%%%%%%% Document Setup %%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Don't like 10pt? Try 11pt or 12pt
\documentclass[11pt]{article}
\RequirePackage[hyphens]{url} % add here so that url loads with hyphens package
\RequirePackage[T1]{fontenc}

\usepackage{times}
% This is a helpful package that puts math inside length specifications
\usepackage{calc}

% Adjust section spacing and text
% Provide a definition to \subparagraph to keep titlesec happy
\let\subparagraph\paragraph
% \usepackage[compact]{titlesec}
\usepackage[explicit]{titlesec}
% get underlining capabilities (\uline{})
% \usepackage{ulem}
% let's me use "if-else" statements in latex
\usepackage{xifthen}

\usepackage{booktabs}
\usepackage{longtable}
\usepackage{array}

% Enable tagging to create versions of the CV for COE and external
\usepackage{tagging}
% Makes for nice units (e.g., in \unit[10]{s} you will see that...)
\usepackage{units}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PAPER SIZE, PAGE NUMBER, AND DOCUMENT LAYOUT NOTES:
% 
% Notice that the includefoot option can be commented OUT in order
% to put the PAGE NUMBER *IN* the bottom margin. This will make the
% effective text area larger.
% 
% IF YOU WISH TO REMOVE THE ``of LASTPAGE'' next to each page number,
% see the note about the +LP and -LP lines below. Comment out the +LP
% and uncomment the -LP.
% 
% IF YOU WISH TO REMOVE PAGE NUMBERS, be sure that the includefoot line
% is uncommented and ALSO uncomment the \pagestyle{empty} a few lines
% below.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Use these lines for letter-sized paper
\usepackage[
% includefoot, % Uncomment to put page number above margin
% marginparwidth=1.2in,     % Length of section titles
% marginparsep=.05in,       % Space between titles and text
margin=1in,               % 1 inch margins
% showframe                % uncomment this to see the frame
]{geometry}

%% More layout: Get rid of indenting throughout entire document
\setlength{\parindent}{0in}

% bibentry is the magic that lets the references be printed right in line via
% the \bibentry command + magic fixes for conflict with hyperref - STUPID
\usepackage{bibentry}
\makeatletter\let\saved@bibitem\@bibitem\makeatother
\usepackage{hyperref}
\makeatletter\let\@bibitem\saved@bibitem\makeatother

% this formats my name in bold in the publications lists
% Note: this requires either (should be found in this repo):
% plain-boldAuthor.bst
% ieeetr-boldAuthor.bst
% IEEEtranDOI-boldAuthor.bst
\usepackage{xstring}
\def\FormatName#1{%
  \IfSubStr{#1}{\UNLcitename}{\textbf{#1}}{#1}%
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Format the Footer
% 
% NOTE: comment the +LP line and uncomment the -LP line to have page
% numbers without the ``of ##'' last page reference)
% 
% NOTE: uncomment the \pagestyle{empty} line to get rid of all page
% numbers (make sure includefoot is commented out above)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\usepackage{fancyhdr,lastpage}
\pagestyle{fancy}
% \pagestyle{empty}      % Uncomment this to get rid of page numbers
\fancyhf{}
% \fancyfootoffset{\marginparsep+\marginparwidth}
\newlength{\footpageshift}
\setlength{\footpageshift}
{0.5\textwidth+0.5\marginparsep+0.5\marginparwidth-2in}
% changes the width of the header/footer line
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{1pt}

% for a centered page numbering scheme
% \rfoot{\hspace{\footpageshift}%
% \parbox{4in}{\, \hfill %
% \arabic{page} of \protect\pageref*{LastPage} % +LP
% \arabic{page}                               % -LP
% \hfill \,}}

% for a right justified page numbering scheme
\rfoot{\small \thepage\ of \pageref*{LastPage} % +LP
  % \arabic{page}                               % -LP
}

%   add my name to the left hand side of the footer
\lfoot{\small \UNLname{}}
\cfoot{\small Last updated: \today}

% Finally, give us PDF bookmarks
\usepackage{color}
\definecolor{darkblue}{rgb}{0.0,0.0,0.3}
\hypersetup{colorlinks,breaklinks,
  linkcolor=darkblue,urlcolor=darkblue,
  anchorcolor=darkblue,citecolor=darkblue}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Change the Section Headers
% requires titlesec package
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% {<command>}[<shape>]{<format>}{<label>}{<sep>}{<before>}{<after>}
% only underline the name of the section % requires ulem package
% \titleformat{\section}{\normalfont\large\bfseries\scshape}{\thesection}{1em}{\uline{#1}}
% underline the whole line
\titleformat{\section}{\normalfont\large\bfseries\scshape}{\thesection}{1em}{#1}[{\titlerule[0.8pt]}]
\titleformat{\subsection}{\normalfont\bfseries}{\thesubsection}{1em}{#1}
\titleformat{\subsubsection}{\normalfont\itshape}{\thesubsubsection}{1em}{#1}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Changes to, and new lists
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% used to change spacing around lists
\usepackage[shortlabels]{enumitem}

% These custom lists are for the outer lists in a section, not for any sublists
\newlist{outeritemize}{itemize}{1}
\setlist[outeritemize,1]{label=\textbullet,leftmargin=0.52in,noitemsep,topsep=0pt,partopsep=0pt}

\newlist{outerdesc}{description}{1}
\setlist[outerdesc,1]{labelindent=0.34in,leftmargin=0.55in,itemsep=10pt,topsep=10pt,parsep=2pt,partopsep=0pt}

\newlist{outerenum}{enumerate}{1}
\setlist[outerenum]{label=\arabic*.,leftmargin=0.55in,noitemsep,partopsep=0pt,topsep=0pt}

% Modifications to basic itemize and enumerate lists
% Requires enumitem package
\setlist[itemize]{noitemsep,topsep=2pt,parsep=0pt,partopsep=0pt}
% \setlist[itemize]{leftmargin=7.5mm,noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}
\setlist[enumerate]{noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}
% \setlist[description]{noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}

\makeatletter

% Now make new lists to support numbering references in the CV

% setup some lengths to help
\newlength{\mybibhang}
\setlength{\mybibhang}{1em}
\newlength{\mybibsep}
{\@listi \global\mybibsep\itemsep \global\advance\mybibsep by\parsep}

% Setup lists for counting journals, conferences, grants, and books. There are
% upward counting lists (e.g., journalbib) and reverse counting lists (e.g., revjournalbib). Each list has associated with it a letter so it can be uniquely
% identified in other documents. "J#" for journals, "C#" for conferences, "B#"
% for books, and "G#" for grants.

% Use etaremune as it lets you avoid having the [start=#] parameter compared to
% the old solution
\RequirePackage{etaremune}

% reverse counting for outer enum (not for inner lists)
% usage \begin{revouterenum} or \begin{revouterenum}[start=#]
\newenvironment{revouterenum}[1][\empty]
{\renewcommand\labelenumi{\theenumi.}%
  \etaremune[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  #1]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endetaremune}

% For counting downwards in generic citations
% usage \begin{revmybib} or \begin{revmybib}[start=#]
\newenvironment{revmybib}[1][\empty]
{\renewcommand\labelenumi{[\theenumi]}%
  \etaremune[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  #1]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endetaremune}

% For counting upwards in generic citations
\newenvironment{mybib}
{\renewcommand\labelenumi{[\theenumi]}%
  \enumerate[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endenumerate}

% For counting downwards in journal citations
% usage \begin{revjournalbib} or \begin{revjournalbib}[start=#]
\newenvironment{revjournalbib}[1][\empty]
{\renewcommand\labelenumi{[J\theenumi]}%
  \etaremune[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  #1]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endetaremune}

% For counting upwards in journal citations
\newenvironment{journalbib}
{\renewcommand\labelenumi{[J\theenumi]}%
  \enumerate[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endenumerate}

% For counting downwards in conference citations
% usage \begin{revconferencebib} or \begin{revconferencebib}[start=#]
\newenvironment{revconferencebib}[1][\empty]
{\renewcommand\labelenumi{[C\theenumi]}%
  \etaremune[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  #1]
}
{\endetaremune}

% For counting upwards in conference citations
\newenvironment{conferencebib}
{\renewcommand\labelenumi{[C\theenumi]}%
  \enumerate[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endenumerate}

% For counting downwards in grants citations
% usage \begin{revgrantsenum} or \begin{revgrantsenum}[start=#]
\newenvironment{revgrantsenum}[1][\empty]
{\renewcommand\labelenumi{[G\theenumi]}%
  \etaremune[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  #1]
}
{\endetaremune}

% For counting upwards in grants enumeration
\newenvironment{grantsenum}
{\renewcommand\labelenumi{[G\theenumi]}%
  \enumerate[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endenumerate}

% For counting downwards in books citations
% usage \begin{revconferencebib} or \begin{revconferencebib}[start=#]
\newenvironment{revbooksbib}[1][\empty]
{\renewcommand\labelenumi{[B\theenumi]}%
  \etaremune[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  #1]
}
{\endetaremune}

% For counting upwards in books citations
\newenvironment{booksbib}
{\renewcommand\labelenumi{[B\theenumi]}%
  \enumerate[
  leftmargin=0.55in,
  topsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt]%
}
%{\endetaremune\vspace{-0.6\baselineskip}}
{\endenumerate}

\makeatother

%%%%%%%%%%%%%%%%%%%%%%%% End Document Setup %%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Helper Commands
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% EXTRA SPACE

% To add some paragraph space between lines.
% This also tells LaTeX to preferably break a page on one of these gaps
% if there is a needed pagebreak nearby.
\newcommand{\blankline}{\quad\pagebreak[3]}
\newcommand{\halfblankline}{\quad\vspace{-0.5\baselineskip}\pagebreak[3]}

%%% FORMATTING MACROS

% Uses hyperref to link DOI
\newcommand\doilink[1]{\href{http://dx.doi.org/#1}{#1}}
% \newcommand\doilink[1]{http://dx.doi.org/#1}
\newcommand\doi[1]{doi:\doilink{#1}}

% For \url{SOME_URL}, links SOME_URL to the url SOME_URL
\providecommand*\url[1]{\href{#1}{#1}}
\renewcommand{\UrlFont}{\ttfamily\footnotesize}
% \providecommand*\url[1]{#1}
% Same as above, but pretty-prints SOME_URL in teletype fixed-width font
% \renewcommand*\url[1]{\href{#1}{\texttt{#1}}}
% \renewcommand*\url[1]{\texttt{#1}}

% For \email{ADDRESS}, links ADDRESS to the url mailto:ADDRESS
\providecommand*\email[1]{\href{mailto:#1}{#1}}
% \providecommand*\email[1]{#1}
% Same as above, but pretty-prints ADDRESS in teletype fixed-width font
% \renewcommand*\email[1]{\href{mailto:#1}{\texttt{#1}}}

% \providecommand\BibTeX{{\rm B\kern-.05em{\sc i\kern-.025em b}\kern-.08em
% T\kern-.1667em\lower.7ex\hbox{E}\kern-.125emX}}
% \providecommand\BibTeX{{\rm B\kern-.05em{\sc i\kern-.025em b}\kern-.08em
% \TeX}}
\providecommand\BibTeX{{B\kern-.05em{\sc i\kern-.025em b}\kern-.08em
    \TeX}}
\providecommand\LyX{{L\kern-0.05em{\sc y\kern-0.025emX}}}
\providecommand\Matlab{\textsc{Matlab}}

% Custom hyphenation rules for words that LaTeX has trouble with
\hyphenation{re-us-a-ble pro-vid-er}

\newcommand\CVheading[1]{{\Large \bf \UNLname{} \hfill \textit{#1}}\\
  \UNLrank{}\\
  University of Nebraska--Lincoln\\
  \UNLdept{}\hfill \textit{Phone:} \UNLphone{}\\
  \UNLaddress{}\hfill  \textit{E-mail:} \email{\UNLemail{}}\\
  Lincoln, NE 68588 USA \hfill \textit{Web:} \UNLwebsite{}\vspace{-5pt}
  \rule{\columnwidth}{2pt}}

%%%%%%%%%%%%%%%%%% For paper contributions and role %%%%%%%%%%%%%%%%%
\usepackage{xargs}

% Commands for putting in addendum to publications

\newcommand{\tier}[1]{%
  \ifthenelse{\equal{#1}{1}}{\textbf{$\mathbf{1^{st}}$ tier}}{}%
  \ifthenelse{\equal{#1}{2}}{\textbf{$\mathbf{2^{nd}}$ tier}}{}%
  \ifthenelse{\equal{#1}{3}}{\textbf{$\mathbf{3^{rd}}$ tier}}{}%
}
\newcommand{\cont}[1]{%
  contribution: #1\%%
}
\newcommand{\accrate}[1]{%
  acceptance rate: #1\%%
}
\newcommand{\impact}[1]{%
  impact: #1%
}

% main command for putting in the addendum
% Parameters:
% Whatever parenthetical text you want bolded after the publication listing
% Examples: 1st tier
\newcommand{\pubaddendum}[1]{%
  \textbf{(#1)}
}% end newcommand


%%%%%%%%%%%%%%%%%%%%%%%% End Helper Commands %%%%%%%%%%%%%%%%%%%%%%%%%%%

% new table columns (I hate LaTeX tables)
% requires array package
\newcolumntype{C}[1]{>{\centering\arraybackslash}m{#1}}   %% centered
\newcolumntype{R}[1]{>{\raggedleft\arraybackslash}m{#1}}  %% right aligned
\newcolumntype{L}[1]{>{\raggedright\arraybackslash}m{#1}}  %% left aligned
\newcolumntype{T}[1]{>{\raggedright\arraybackslash}p{#1}} %% top left aligned
\newcolumntype{P}[1]{>{\centering\let\newline\\\arraybackslash}p{#1}}
