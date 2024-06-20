USER=rmanzana
MAIL=rmanzana@student.42barcelona.com
export USER
export MAIL

function mkcd(){mkdir "$1" && cd "$1" && pwd;}
function vagoc(){cc -Wall -Werror -Wextra "$1";}
function warmach(){bash ~/libft-war-machine/grademe.sh;}
function warlog(){vim ~/libft-war-machine/deepthought;}
