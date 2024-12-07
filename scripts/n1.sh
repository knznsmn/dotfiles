#!/usr/bin/env bash
function catHeader() {
  local author="Written by Julius Cinco Cesar"
  local date=$(date +"%B %d, %Y")
  local hr_lens=49

  if [ "$1" = "html" ]; then
    local br_ouve="<!"
    local br_ferm="->"
    local hr_bars="-"
  else
    local br_ouve="/*"
    local br_ferm="*/"
    local hr_bars="*"
  fi

  echo -n "$br_ouve"
  local i=0
  while [ $i -lt $hr_lens ]; do
    echo -n "$hr_bars"
    (( i++ ));
  done
  echo -e "\n\n"
  echo -e "\t$author"
  echo -e "\t$date"
  echo -e "\n"
  local i=0
  while [ $i -lt $hr_lens ]; do
    echo -n "$hr_bars"
    (( i++ ));
  done
  echo -e "$br_ferm"
}

function initProjet() {

mkdir assets

cat <<EOL > index.html
$(catHeader "html")
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
    <link rel="stylesheet" href="assets/css/styles.css">
  </head>
  
  <body>
    <script src="assets/js/main.js"></script>
  </body>
</html>
EOL

mkdir -p assets/css assets/js

cat <<EOL > assets/css/styles.css
$(catHeader)
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}
/* 1. Use a more-intuitive box-sizing model */
*, *::before, *::after {
  box-sizing: border-box;
}

/* 2. Remove default margin */
* {
  margin: 0;
}

body {
  /* 3. Add accessible line-height */
  line-height: 1.5;
  /* 4. Improve text rendering */
  -webkit-font-smoothing: antialiased;
}

/* 5. Improve media defaults */
img, picture, video, canvas, svg {
  display: block;
  max-width: 100%;
}

/* 6. Inherit fonts for form controls */
input, button, textarea, select {
  font: inherit;
}

/* 7. Avoid text overflows */
p, h1, h2, h3, h4, h5, h6 {
  overflow-wrap: break-word;
}

/* 8. Improve line wrapping */
p {
  text-wrap: pretty;
}
h1, h2, h3, h4, h5, h6 {
  text-wrap: balance;
}

/*
  9. Create a root stacking context
*/
#root, #__next {
  isolation: isolate;
}
EOL

cat <<EOL > assets/js/main.js
$(catHeader)

// Elements Bindings

EOL

echo "Project structure has been created successfully."
}

function showMenu() {
  echo -e "\nSyntax: $0 [PARAM] [PARAM]\n"
  echo -e "\t -i"
  echo -e "\t -h\n"
}

# MAIN()

if [[ $# -lt 1 ]]; then
  showMenu
elif [[ $1 -eq i ]]; then
  initProjet
else
  echo "Not finished of this part yet."
fi
