<?php

function logged_in_redirect(){
if(logged_in()===true){
header('Location:index.php');
exit();
}

}


function protect_page(){
if(logged_in()=== false){
echo "alert('Sorry, you need to be login to access');";
}
}

function array_sanitize(&$item){
$item=mysqli_real_escape_string($item);
}

function sanitize($data){
return mysqli_real_escape_string($data);
}
function output_errors($errors){
return '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>';
}
?>