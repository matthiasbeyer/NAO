#!/usr/bin/env sh


[ -z "$1" ] && exit 1;


#initialize a var
testy="";


#extract last tag, checking whether there acutally is a tag
if testy="$(git describe --tags --abbrev=0 HEAD)";
    then testy="$( #expand version string
        echo "$testy" | sed 's/^v/Version /;s/-rc/ Release Kandidat/;';
    )";
    else testy="Unbekannte Version";
fi >>/dev/null 2>&1;



#print version command
cat <<EOS > $1
\newcommand{\version}{$testy}
EOS

