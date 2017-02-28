<?php
session_start();
include 'Login/connect1.php';
include 'Login/general.php';
include 'Login/users.php';
if(logged_in()=== true){
$session_user_id=$_SESSION['uname'];
$user_data=user_data($session_user_id,'firstname','lastname','uname','dob','sex','email','pass','country','hint','answer');
//echo $user_data['username'];
if(user_active($user_data['uname'])=== false){ //this functions checks if user deactivate account he/she will be logout from all browsers
session_destroy();
header('Location:login1.php');
exit();
}

}

$errors=array();
?>