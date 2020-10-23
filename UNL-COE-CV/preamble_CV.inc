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
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 

%%%%%%%%%%%%%%%%%%%%%%%%%%%% Document Setup %%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Don't like 10pt? Try 11pt or 12pt
\documentclass[11pt]{article}
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
% 

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

% used to change spacing around lists
\usepackage[shortlabels]{enumitem}

% bibentry is the magic that lets the references be printed right in line via
% the \bibentry command + magic fixes for conflict with hyperref - STUPID
\usepackage{bibentry}
\makeatletter\let\saved@bibitem\@bibitem\makeatother
\usepackage{hyperref}
\makeatletter\let\@bibitem\saved@bibitem\makeatother

% this formats my name in bold in the publications lists
% Note: this requires either:
% plain-boldAuthor.bst
% ieeetr-boldAuthor.bst
% IEEEtranDOI-boldAuthor.bst
\usepackage{xstring}
\def\FormatName#1{%
  \IfSubStr{#1}{\UNLcitename}{\textbf{#1}}{#1}%
}

%% Format the Footer
% 
% NOTE: comment the +LP line and uncomment the -LP line to have page
% numbers without the ``of ##'' last page reference)
% 
% NOTE: uncomment the \pagestyle{empty} line to get rid of all page
% numbers (make sure includefoot is commented out above)

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
% this doesn't seem to work.
% \rfoot{\small \arabic{page} of \protect\pageref*{LastPage} % +LP
%   % \arabic{page}                               % -LP
% }

\usepackage{units}

%   add my name to the left hand side of the footer
\lfoot{\small \UNLname{}}
\cfoot{\small Last updated: \today}

% Finally, give us PDF bookmarks
\usepackage{color}
\definecolor{darkblue}{rgb}{0.0,0.0,0.3}
\hypersetup{colorlinks,breaklinks,
  linkcolor=darkblue,urlcolor=darkblue,
  anchorcolor=darkblue,citecolor=darkblue}

% Change the Section Headers
% requires titlesec package

% {<command>}[<shape>]{<format>}{<label>}{<sep>}{<before>}{<after>}
% only underline the name of the section % requires ulem package
% \titleformat{\section}{\normalfont\large\bfseries\scshape}{\thesection}{1em}{\uline{#1}}
% underline the whole line
\titleformat{\section}{\normalfont\large\bfseries\scshape}{\thesection}{1em}{#1}[{\titlerule[0.8pt]}]
\titleformat{\subsection}{\normalfont\bfseries}{\thesubsection}{1em}{#1}
\titleformat{\subsubsection}{\normalfont\itshape}{\thesubsubsection}{1em}{#1}

% These custom lists are for the first list in a section, not for any sublists
\newlist{myitemize}{itemize}{1}
\setlist[myitemize,1]{label=\textbullet,leftmargin=0.52in,noitemsep,topsep=0pt,partopsep=0pt}

\newlist{mydesc}{description}{1}
\setlist[mydesc,1]{labelindent=0.34in,leftmargin=0.55in,itemsep=10pt,topsep=10pt,parsep=2pt,partopsep=0pt}

\newlist{myenum}{enumerate}{1}
\setlist[myenum]{label=\arabic*.,%
  leftmargin=0.55in,
  noitemsep,
  partopsep=0pt,
  topsep=0pt}

% Requires enumitem package
\setlist[itemize]{noitemsep,topsep=2pt,parsep=0pt,partopsep=0pt}
% \setlist[itemize]{leftmargin=7.5mm,noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}
\setlist[enumerate]{noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}
% \setlist[description]{noitemsep,topsep=0pt,parsep=0pt,partopsep=0pt}

% Simpler bibsections for CV sections
% (thanks to natbib for inspiration)
% 
% * For lists of references with hanging indents and no numbers:
% 
% \begin{mybibsection}
% \item ...
% \end{bibsection}
% 
% * For numbered lists of references (with hanging indents):
% 
% \begin{mybibenum}
% \item ...
% \end{bibenum}
% 
% Note that bibenum numbers continuously throughout. To reset the
% counter, use
% 
% \restartlist{bibenum}
% 
% at the place where you want the numbering to reset.

\makeatletter
\newlength{\mybibhang}
\setlength{\mybibhang}{1em}
\newlength{\mybibsep}
{\@listi \global\mybibsep\itemsep \global\advance\mybibsep by\parsep}
\newlist{mybibsection}{itemize}{3}
\setlist[mybibsection]{label=,
  leftmargin=\mybibhang,%
  itemindent=-\mybibhang,
  % itemsep=\mybibsep,parsep=\z@,partopsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  topsep=0pt,
  after=\vspace{10pt}}
\let\oldendmybibsection\endmybibsection
\def\endmybibsection{\oldendmybibsection\vspace{-.6\baselineskip}}

\newlist{mybibenum}{enumerate}{3}
\setlist[mybibenum]{label=[\arabic*],
  resume,
  leftmargin=0.55in,
  % leftmargin={\mybibhang+0.55in},
  % leftmargin={\mybibhang+\widthof{[9999]}},%
  % itemindent=-\mybibhang,
  % itemsep=\mybibsep,parsep=\z@,partopsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  topsep=0pt,
  after=\vspace{10pt}}
\let\oldendmybibenum\endmybibenum
\def\endmybibenum{\oldendmybibenum\vspace{-.6\baselineskip}}

\newlist{journalbib}{enumerate}{3}
\setlist[journalbib]{label=[J\arabic*],
  resume,
  leftmargin=0.55in,
  % leftmargin={\mybibhang+0.55in},
  % leftmargin={\mybibhang+\widthof{[9999]}},%
  % itemindent=-\mybibhang,
  % itemsep=\mybibsep,parsep=\z@,partopsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  topsep=0pt,
  after=\vspace{10pt}}
\let\oldendjournalbib\endjournalbib
\def\endjournalbib{\oldendjournalbib\vspace{-.6\baselineskip}}

\newlist{conferencebib}{enumerate}{3}
\setlist[conferencebib]{label=[C\arabic*],
  resume,
  leftmargin=0.55in,
  % leftmargin={\mybibhang+0.55in},
  % leftmargin={\mybibhang+\widthof{[9999]}},%
  % itemindent=-\mybibhang,
  % itemsep=\mybibsep,parsep=\z@,partopsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  topsep=0pt,
  after=\vspace{10pt}}
\let\oldendconferencebib\endconferencebib
\def\endconferencebib{\oldendconferencebib\vspace{-.6\baselineskip}}

\newlist{grantsenum}{enumerate}{3}
\setlist[grantsenum]{label=[G\arabic*],
  resume,
  leftmargin=0.55in,
  % leftmargin={\mybibhang+0.55in},
  % leftmargin={\mybibhang+\widthof{[9999]}},%
  % itemindent=-\mybibhang,
  % itemsep=\mybibsep,parsep=\z@,partopsep=0pt,
  itemsep=2pt,
  parsep=\z@,
  partopsep=0pt,
  topsep=0pt,
  after=\vspace{10pt}}
\let\oldendgrantsenum\endgrantsenum
\def\endgrantsenum{\oldendgrantsenum\vspace{-.6\baselineskip}}

\makeatother

%%%%%%%%%%%%%%%%%%%%%%%% End Document Setup %%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%%%%%%%%%%%%%%%%%%%%%%%%%% Helper Commands %%%%%%%%%%%%%%%%%%%%%%%%%%%%

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

% Command for putting in addendum to publications

% main command for putting in the addendum
% Parameters:
% #1 (optional) = what tier (first, second, third)
% #2 (optional) = other information (h-index, impact factor, etc.)
% Usage examples:
% \pubaddendum[1] yields "(1st tier)" in bold
% \pubaddendum[2][25\% acceptance rate] yields "(2nd tier, 25% acceptance rate)" in bold
% \pubaddendum[][impact: 5.138] yields "(impact: 5.138)" in bold
\newcommandx{\pubaddendum}[2][1=, 2=]{%
  \textbf{(}%
    \ifthenelse{\equal{#1}{1}}{\textbf{$\mathbf{1^{st}}$ tier}}{}%
    \ifthenelse{\equal{#1}{2}}{\textbf{$\mathbf{2^{nd}}$ tier}}{}%
    \ifthenelse{\equal{#1}{3}}{\textbf{$\mathbf{3^{rd}}$ tier}}{}%
    \ifthenelse{\isempty{#2}}{}{\ifthenelse{\isempty{#1}}{}{, }\textbf{#2}}%
  \textbf{)}% final paren
}% end newcommand


%%%%%%%%%%%%%%%%%%%%%%%% End Helper Commands %%%%%%%%%%%%%%%%%%%%%%%%%%%

% new table columns (I hate LaTeX tables)
% requires array package
\newcolumntype{C}[1]{>{\centering\arraybackslash}m{#1}}   %% centered
\newcolumntype{R}[1]{>{\raggedleft\arraybackslash}m{#1}}  %% right aligned
\newcolumntype{L}[1]{>{\raggedright\arraybackslash}m{#1}}  %% left aligned
\newcolumntype{T}[1]{>{\raggedright\arraybackslash}p{#1}} %% top left aligned
\newcolumntype{P}[1]{>{\centering\let\newline\\\arraybackslash}p{#1}}
