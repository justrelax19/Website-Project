<?php


/*function user_count(){
return mysql_result(mysql_query('SELECT COUNT(`user_id`) FROM users WHERE active=1'),0) ;
}*/

/*function user_data($user_id){
$data=array();

$user_id=(int)$user_id;

$func_num_args=func_num_args();

//echo $func_num_args; echos the arguments passed in the function it is useful for looping 

$func_get_args=func_get_args();

//print_r($func_get_args); Prints the array in sequential order (print arguments)

if($func_get_args>1){

unset($func_get_args[0]); //it will unset the 0 array element of array ie session id

$fields= '`' . implode('` , `',$func_get_args). '`';

$data=mysql_fetch_assoc(mysql_query("SELECT $fields FROM users WHERE user_id='$user_id'"));

return $data;



}


}*/

function logged_in(){
return (isset($_SESSION['uname'])) ? true : false;
}

function email_exists($email){
$email=sanitize($email);
return (mysql_result(mysqli_query("SELECT COUNT('uname') FROM signup WHERE email = '$email'"),0)==1) ? true : false;
}


function user_exists($username){
$username=sanitize($username);
return (mysql_result(mysqli_query("SELECT COUNT('uname') FROM signup WHERE uname = '$username'",$link),0)==1) ? true : false;
}

function user_id_from_username($username){
$username=sanitize($username);
return mysql_result(mysqli_query("SELECT uname from signup where username = '$username'"), 0 ,'uname' );
}

function login($username,$password){
$user_id=user_id_from_username($username);
$username=sanitize($username);
$password=md5($password);
return (mysql_result(mysqli_query("SELECT COUNT('uname') from users where username = '$username' AND password='$password'"),0)==1) ? $user_id : false;
}
?>