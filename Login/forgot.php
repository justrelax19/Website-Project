<!doctype html>
<html>
	<head>
		<meta charset='utf-8'>
		<title>Forgot Password </title>
		<link rel="stylesheet" href="../pages/main.css">
	</head>
	<body>
	<?php
	include("connect1.php");
		$email=$hint=$answer="";
		if($_SERVER["REQUEST_METHOD"]=="POST")
		{
			$email=$_POST['email'];
			$hint=$_POST['hint'];
			$answer=$_POST['answer'];
		
		$sql= "SELECT * From signup WHERE email='$email'";
		$extract=$link->query($sql);
		$res = mysqli_query($link,$sql);
		$numrows = mysqli_num_rows($res);
		if ($numrows!=0)
		{
			
			while($row = mysqli_fetch_assoc($res))
			{
				$dbemail = $row['email'];
				$dbanswer= $row['hans'];
				$dbhint= $row['hques'];
				
			}
			if($email==$dbemail&&$hint==$dbhint&&$answer==$dbanswer)                 //for forgot password too
				{
				session_start();
					$_SESSION["forgotpwdemail"]=$email;
					header("Location:forgot2.php");
					
				}
				else
				{
					echo "Are You a new User? You seems to be already registered! Please try again with different mail id!";
					
				}
		}
		}
	
	?>
	<form method="post" action="<?php echo $_SERVER['PHP_SELF']?>">
	<fieldset>
		<legend><strong>Forgot Password</strong></legend>
		Enter your E-mail:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="email" name="email" required>
	  <br><br>
		Select your hint question:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		
	<select id="hint" name="hint">
	  <option value="Where were you born?">Where were you born?</option>
	  <option value="What is your favourite book's name?">What is your favourite book's name?</option>
	  <option value="What is your nickname?">What is your nickname?</option>
	  <option value="What is your mother's name?">What is your mother's name?</option>
	  <option value="What is your father's middle name?">What is your father's middle name?</option>
	  </select>
	  <br><br>
	   Answer:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="text" name="answer" required>
	</fieldset>
	
	<input type="submit" value="Next">
	  <input type="reset" value="Reset">
</form>
</body>
	  </html>
