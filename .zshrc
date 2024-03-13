if command -v tmux &> /dev/null && [ -z "$TMUX" ]; then
    tmux attach -t default || tmux new -s default
fi

export ZSH="$HOME/.oh-my-zsh"

plugins=(
    docker
    z
)

autoload -U compinit

source ~/antigen.zsh

antigen bundle git
antigen bundle zsh-users/zsh-autosuggestions
antigen bundle zsh-users/zsh-syntax-highlighting    

antigen theme gozilla
antigen apply

ZSH_THEME=gentoo

# Add here your aliases or functions

autoload -U compinit
source $ZSH/oh-my-zsh.sh
