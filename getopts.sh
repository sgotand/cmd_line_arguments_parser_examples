#!/bin/bash
set -eu

usage_exit() {
        echo "Usage: $0 [-a] [-d dir] item ..." 1>&2
        echo "This is a template for bash builtin getopts" 1>&2
        exit 1
}

while getopts ad:h OPT
do
    case $OPT in
        a)  FLAG_A=1
            ;;
        b)  VALUE_B=$OPTARG
            ;;
        d)  VALUE_D=$OPTARG
            ;;
        h)  usage_exit
            ;;
        \?) usage_exit
            ;;
    esac
done

[[ $# = 0 ]] && usage_exit

echo flag for -a ${FLAG_A:-0}
echo value for -b ${VALUE_B:-None}
echo value for -d ${VALUE_D:-None}

shift $((OPTIND - 1))
printf "Remaining arguments are: %s\n$*"
