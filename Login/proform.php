<html>
<title>SignUp</title>
<head>

	<link href='../pages/main.css' rel='stylesheet'>
	<link href='form.css' rel='stylesheet'>	
</head>
<body>
<?php
// define variables and set to empty values
$nameErr = $emailErr  = $passwordErr = "";
$name = $email = $password = $fname=$lname=$uname=$birth=$ss=$countries=" ";
$submitemail= $submitpassword=$submitfname=$submitlname=$submituname=$submitbirth=$submitss=$submitcountries=$submithint=$submitans="";


if ($_SERVER["REQUEST_METHOD"] == "POST")
{
    
      $submitemail = $_POST['email'];
      $submitpassword = $_POST['pass'];
	     $submitfname = $_POST['firstname'];
      $submitlname = $_POST['lastname'];
	     $submituname = $_POST['uname'];
      $submitbirth = $_POST['dob'];
	     $submitss = $_POST['sex'];
      $submitcountries = $_POST['country'];
	  $submithint=$_POST['hint'];
	  $submitans=$_POST['answer'];
	  include("connect1.php");
	  if(!preg_match('/^(?=.*\d)(?=.*[@#\-_$%^&+=§!\?])(?=.*[a-z])(?=.*[A-Z])[0-9A-Za-z@#\-_$%^&+=§!\?]{8,20}$/', $_POST["pass"]))
	  {
	  
	  echo "Password doesn't meet the requirements! Please try again!";
      echo "<script>
      alert('Password doesn't meet the requirements! Please try again!');
      window.location='http://localhost//SignUp/proform.php';
      </script>";
	  }
      else
	  {
	  $submitpasswordencr=md5($submitpassword) or (mysqli_error($link));  
      if($submitemail && $submitpasswordencr)
     {
      
	  $sql= "SELECT * From signup WHERE email='$submitemail'";
	 $extract=$link->query($sql);
      $res = mysqli_query($link,$sql);
	$numrows = mysqli_num_rows($res);
	
	if ($numrows!=0)
	{
		while($row = mysqli_fetch_assoc($res))
		{
			
			$dbemail = $row['email'];
			$dbms= $row['uname']
			//$dbpassword = $row['''password'];
		}
		if($submitemail==$dbemail && $submituname==$dbms)                 //for forgot password too
		{
		//header('Location:http://localhost//programs/error3.php');
		echo "Are You a new User? You seems to be already registered! Please try again with different mail id!";
      echo "<script>
      alert('Are You a new User? You seems to be already registered! Please try again with different mail id!');
      window.location='http://localhost//SignUp/proform.php';
      </script>";
		}
	}
			else	
	{
		
	  $write="INSERT INTO signup(fname,lname,uname,dob,gender,email,password,country,hques,hans) VALUES('$submitfname','$submitlname','$submituname','$submitbirth','$submitss','$submitemail','$submitpasswordencr','$submitcountries','$submithint','$submitans')";
	 // $extract1=$link->query($write);
	 // $nn=mysqli_query($link,$write);
	  if(!(mysqli_query($link,$write)))
	  {
		  echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
	  }
	  else{
	 // header('Location:http://localhost//programs/successful.php');
	  echo "Successfully Logged In Enjoy! Please click on Home to see more!";
      echo "<script>
      alert('Successfully Logged In Enjoy! Please click on home! ');
    window.location='http://localhost//Pages/index.htm';
	
	 </script>";
	}
	}
      
	  }
	  }
	  $_SERVER["REQUEST_METHOD"]="";
}
	
	 
	 

function test_input($data)
{
     $data = trim($data);
     $data = stripslashes($data);
     $data = htmlspecialchars($data);
     return $data;
}

?>
<div id="allcontent">
<form action="proform.php" method="post">

	<fieldset>
		<legend><strong>Your Profile</strong></legend>
		First name: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="text" id="fname" name="firstname" required>
		<br><br>
		Last name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="text" id="lname" name="lastname" required>
		<br><br>
		User name:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="text" id="uname" name="uname" required>
		<br><br>
	  
	  Date of Birth:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="date" id="birth" name="dob" max="1997-11-01" required>
	  <p><strong>Note:</strong>
	  You must be atleast 18 years old.</p>
		Gender:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="radio" id="ss"name="sex" value="male" checked>Male
	  
	  <input type="radio" id="ss" name="sex" value="female">Female
	  <br><br>
	  E-mail:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="email" name="email" id="email" required>
	  <br><br>
	 <!-- Confirm E-mail:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="email" name="email" id="cemail"  onblur="confirmEmail()" required>
	  <br><br>-->
	  New Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="password" name="pass" id="password" onclick="pwDisp()" onfocus="pwDisp()" required> 
	  <script>
		function pwDisp()
		{
			alert(" At least one lowercase character\n At least one uppercase character\n At least one digit\n at least one special sign of @#-_$%^&+=§!?\nRequired between 8 t0 20 Characters");
			
		}
	  </script>
	  <br><br>
	  Confirm Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="password" name="pass" id="cpass" onblur="confirmPass()" required>
	  <br><br>
	  Country you Support:&nbsp;&nbsp;&nbsp;
	  <input list="countries"  name="country" required>
	<datalist id="countries">
	  <option value="Argentina">
	  <option value="Belgium">
	  <option value="Brazil">
	  <option value="Chile">
	  <option value="England">
	  <option value="Czech Republic">
	  <option value="Denmark">
	  <option value="France">
	  <option value="Germany">
	  <option value="Italy">
	  <option value="Netherlands">
	  <option value="Poland">
	  <option value="Portugal">
	  <option value="Spain">
	  <option value="Sweden">
	  <option value="Uruguay">
	  </datalist>
	<br><br>
		<!--State/County:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="text" name="state">
		<br><br>
		City/District:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="text" name="city">
		<br><br>-->
		<!--Time Zone:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input list="timezone" name="timezone">
	<datalist id="timezone">
	  <option value="GMT +00:00">
	  <option value="GMT +01:00">
	  <option value="GMT +02:00">
	  <option value="GMT +03:00">
	  <option value="GMT +03:30">
	  <option value="GMT +04:00">
	  <option value="GMT +04:30">
	  <option value="GMT +05:00">
	  <option value="GMT +05:30">
	  <option value="GMT +06:00">
	  <option value="GMT +06:30">
	  <option value="GMT +07:00">
	  <option value="GMT +08:00">
	  <option value="GMT +09:00">
	  <option value="GMT +10:00">
	  <option value="GMT +10:30">
	  <option value="GMT +11:00">
	  <option value="GMT +11:30">
	  <option value="GMT +12:00">
	  <option value="GMT +13:00">
	  <option value="GMT +14:00">
	  <option value="GMT -01:00">
	  <option value="GMT -02:00">
	  <option value="GMT -03:00">
	  <option value="GMT -03:30">
	  <option value="GMT -04:00">
	  <option value="GMT -05:00">
	  <option value="GMT -06:00">
	  <option value="GMT -07:00">
	  <option value="GMT -08:00">
	  <option value="GMT -08:30">
	  <option value="GMT -09:00">
	  <option value="GMT -09:30">  
	  <option value="GMT -10:00">
	  <option value="GMT -11:00">
	  <option value="GMT -12:00">
	  </datalist>
	  <br><br>
	  Post Code/Zip Code:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="number" name="code" required>
		<br><br>-->
		Select a hint question:
		<input list="hint" name="hint" required>
	<datalist id="hint">
	  <option value="Where were you born?">
	  <option value="What is your favourite book's name?">
	  <option value="What is your nickname?">
	  <option value="What is your mother's name?">
	  <option value="What is your father's middle name?">
	  </datalist>
	  <br><br>
	  Answer:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="text" id="ans" name="answer" required>&nbsp;&nbsp;&nbsp;&nbsp;
	  <br>
	  <input type="checkbox" name="t&c" value="t&c" required> I have read <a href="../Pages/t&c.htm" target="_blank" style="text-decoration:none; color:black;">Terms & Conditions</a>
	  </fieldset>
	  <input type="submit" value="Next">
	  <input type="reset" value="Reset">
	</form>
	</div>
</body>	
</html>