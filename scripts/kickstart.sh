#!/bin/bash


mkdir assets

cat <<EOL > assets/index.html
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
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}
EOL

echo "// Element Bindings" > assets/js/main.js

echo "Project structure has been created successfully."

