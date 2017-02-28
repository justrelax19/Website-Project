<!DOCTYPE html>
<html>
<head>
<script>
function validateForm() {
    var x = document.getElementById('txt').value;
	var y=document.getElementById('txt1').value;
    if (x == null || x == "") {
        alert("Name must be filled out");
        return false;
    }
	if(y.length<10)
	{
		alert("phn no must be of length 10");
		return false;
	}
}

/*function CheckPassword(inputtxt)   
{   
var passw = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,20}$/;  
if(inputtxt.value.match(passw))   
{   
alert('Correct, try another...')  
return true;  
}  
else  
{   
alert('Wrong...!')  
return false;  
}  
} */ 
</script>
</head>


<body>

<form name="myForm" action="welcome.php"
onsubmit="return validateForm()" method="post">
Name: <input type="text" id='txt' name="fname">
Telephone: <input type="text" id='txt1' name="phone">
<input type="submit" value="Submit">
</form>

</body>
</html>
