"<User Interface>
syntax on " Enable syntax processing
set mouse=a "Enable mouse
set clipboard=unnamedplus
set number "Show line numbers
set relativenumber
set cursorline
set showcmd "Show the last command in bottom bar
set wildmenu "Visual autocompletion for command menu
set showmatch "Highlight matching [{()}]
set ruler "Always show cursor position
set listchars=eol:⏎,tab:\>\-,trail:⎵,nbsp:.
set foldmethod=syntax "Fold based on indention levels
set foldcolumn=1 "Enable mouse to open and close folds
set nofoldenable "Open files without closed folds
set confirm "Display a confirmation dialog when closing an unsaved file

"<Indent>
filetype indent on "Enable indentation rules that are file-type specific
set tabstop=4 "Indent using four spaces
set softtabstop=4 "Number of spaces in <Tab>
set shiftwidth=4 "When shifting, indent using four spaces
set autoindent "New lines inherit the indentation of previous lines
set smarttab "Insert "tabstop" number of spaces with the "tab" key
set smartindent "Do smart autoindenting when starting a new line

"<Search>
set hlsearch "Search highlighting
set incsearch "Incremental search that shows partial matches
set smartcase "Automatically switch search to case-sensitive when search query contains an uppercase letter

call plug#begin('~/.vim/plugged')

" Temas
Plug 'ajlende/atlas.vim'
Plug 'morhetz/gruvbox'

" IDE
Plug 'easymotion/vim-easymotion'
Plug 'scrooloose/nerdtree'
Plug 'jiangmiao/auto-pairs'
Plug 'ap/vim-buftabline'
Plug 'vim-airline/vim-airline'
Plug 'tpope/vim-commentary'

call plug#end()

set background=dark
colorscheme nms
let NERDTreeQuitOnOpen=1
let mapleader=" "

nmap <Leader>s <Plug>(easymotion-s2)

inoremap <c-n> <Esc>:NERDTreeToggle<CR>
nnoremap <c-n> <Esc>:NERDTreeToggle<CR>

nmap <Leader>p :Stdheader<CR>

nmap <Leader>x :bd<CR>
nnoremap <S-Tab> :bprev<CR>
nnoremap <TAB> :bnext<CR>

nmap <Leader>q :q<CR>
nmap <Leader>w :w<CR>

nmap <Leader>t :set list<CR>
nmap <Leader>tt :set nolist<CR>

inoremap <expr> <Tab>   pumvisible() ? "\<C-n>" : "\<Tab>"
inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
inoremap <expr> <cr>    pumvisible() ? asyncomplete#close_popup() : "\<cr>"
