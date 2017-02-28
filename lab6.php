<html>
<body>
<?php
	$states=array('Mississippi', 'Alabama' ,'Texas', 'Massachusetts', 'Kansas');
	$statesarray=array();
	foreach($states as $state)
	{
		if(preg_match('/xas$/',($state)))
		$statesarray[0]=$state;
	}
	foreach($states as $state)
	{
		if(preg_match('/^k.*s$/i',($state)))
		$statesarray[1]=$state;
	}
	foreach($states as $state)
	{
		if(preg_match('/^M.*s$/',($state)))
		$statesarray[2]=$state;
	}
	foreach($states as $state)
	{
		if(preg_match('/a$/',($state)))
		$statesarray[3]=$state;
	}
	foreach($states as $state)
	{
		if(preg_match('/^M/',($state)))
		$statesarray[4]=$state;
	}
	foreach($statesarray as $element => $value)
	echo "element $element of statesarray is $value <br/>";
	?>