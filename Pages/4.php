<html>
<head>
<style>
@import url(https://fonts.googleapis.com/css?family=PT+Sans);
body{
	font-family:'pt sans',cursive;
}
h3{
	color:white;
}
.cl{
	position:absolute;
	top:25px;
	left:85%;
	
}
</style>
</head>
<body>
<h2 style="color:white;">GROUP D STAGE</h2>
<?php
session_start();
include('connect1.php');
$qq="select * from d";
$ress=$link->query($qq);
$top="400px";
ob_start();
$data=0;
while($data<$_SESSION["val"])
{
	$ress->fetch_assoc();
	$data++;
}
	$row=$ress->fetch_assoc();
$var1=$row["name"];
$ress=$link->query($qq);
$data=0;
while($data<$_SESSION["op"])
{
$ress->fetch_assoc();
$data++;
}
$row=$ress->fetch_assoc();
$var2=$row["name"];
echo "<h3>$var1</h3>";
echo "<img src='../images/flag/$var1.jpg' width='190px' height='120px' style='float:left;position:absolute; top:'$top';'>";
echo "<h3 class='cl'>$var2</h3>";
echo "<img src='../images/flag/$var2.jpg' width='190px' height='120px' style='float:right;'>"; 
$sql1="select team_confidence,team_popularity,attack,mid,defence from team where name='$var1'";
$result1=$link->query($sql1);
$sql2="select team_confidence,team_popularity,attack,mid,defence from team where name='$var2'";
$result2=$link->query($sql2);
$sql3="select * from player where skill_level>=85 and tname='$var1'";
$result3=$link->query($sql3);
$sql4="select * from player where skill_level>=85 and tname='$var2'";
$result4=$link->query($sql4);
$winprobA=0;
$winprobB=0;
$x=rand(1,80);
$y=rand(1,80);
$winprobA+=$x;
$winprobB+=$y;

if($result1->num_rows>0 && $result2->num_rows>0)
{
	while($row1=$result1->fetch_assoc() && $row2=$result2->fetch_assoc())
	{
		if($row1["team_confidence"]>$row2["team_confidence"])
		{
			$winprobA+=($row1["team_confidence"]-$row2["team_confidence"])/10;			
		}
		else
		{
			$winprobB+=($row2["team_confidence"]-$row1["team_confidence"])/10;	
		}
		if($row1["team_popularity"]>$row2["team_popularity"])
		{
			$winprobA+=($row1["team_popularity"]-$row2["team_popularity"])/10;			
		}
		else
		{
			$winprobB+=($row2["team_popularity"]-$row1["team_popularity"])/10;	
		}
		$x=$row1["attack"]+$row1["mid"]+$row1["defence"];
		$y=$row2["attack"]+$row2["mid"]+$row2["defence"];
		if($x>$y)
		{
			$winprobA+=($x-$y)/10;
		}
		else
		{
			$winprobB+=($y-$x)/10;
		}
		
		if($result3->num_rows>$result4->num_rows)
		{
			$q=$result3->num_rows-$result4->num_rows;
			$q=$q/40;
			$winprobA+=$q;
		}
		else
		{
			$q=$result4->num_rows-$result3->num_rows;
			$q=$q/40;
			$winprobB+=$q;
		}
		$gs1=rand(1,10);
		$gs2=rand(1,10);
		echo "<br/><br/><br></br></br></br>";
		$top="100px";
		if($winprobA-$winprobB>0.0001)
		{
			$sql5="update team set team_confidence=team_confidence+2 where name='$var1'";
			$link->query($sql5);
			$sql6="update team set team_popularity=team_popularity+2 where name='$var1'";
			$link->query($sql6);
			$sql7="update team set attack=attack+2 where name='$var1'";
			$link->query($sql7);
			$sql8="update d1 set points+='3',goal_scored+='$gs1',goal_diff+='$gs1-$gs2' where tname='$var1'";
			$link->query($sql8);
			$sql9="update d1 set points+=0,goal_scored+=$gs2,goal_diff-=($gs1-$gs2) where tname='$var2'";
			$link->query($sql9);
			echo "<div align='center'><font color='white'>$var1 Won the match</font></div>";
		}
		else
		{
			$sql5="update team set team_confidence=team_confidence-2 where name='$var2'";
			$link->query($sql5);
			$sql6="update team set team_popularity=team_popularity-2 where name='$var2'";
			$link->query($sql6);
			$sql7="update team set defence=defence-2 where name='$var2'";
			$link->query($sql7);
			$dd=$gs2-$gs1;
			$sql8="update d1 set points='3',goal_scored='$gs2',goal_diff='$dd' where tname='$var2'";
			$link->query($sql8);
			$sql9="update d1 set points+=0,goal_scored+=$gs1,goal_diff-=($gs2-$gs1) where tname='$var1'";
			$link->query($sql9);
			echo "<div align='center' ><font color='white'>$var2 won the match</font></div>";
			}
	}
}
$_SESSION["op"]++;
if($_SESSION["op"]>3)
{
	$_SESSION["val"]++;
	$_SESSION["op"]=$_SESSION["val"];
	$_SESSION["op"]++;
}
$d=$_SESSION["match"];
if($_SESSION["val"]<3)
echo "<div align='center'><a href='$d.php' target='names' style='color:white;text-decoration:none;'><h3>Next Match</h3></a></div>";
else
{
	$_SESSION["match"]++;
	$d=$_SESSION["match"];
	echo "<div align='center'><a href='$d.php' target='names' style='color:white;text-decoration:none;'><h3>Quarter Final Match</h3></a></div>";
	
	$sql="select tname from a1 where points=(select max(points) from a1)";
$res=$link->query($sql);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a1="insert into quarter_final values('$s',1)";
$link->query($a1);
$sql1="update a1 set points=-1 where tname='$s'";
$link->query($sql1);
$sql2="select tname from a1 where points=(select max(points) from a1)";
$res=$link->query($sql2);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',2)";
$link->query($a2);
$sql4="select tname from b1 where points=(select max(points) from b1)";
$res=$link->query($sql4);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',3)";
$link->query($a2);
$sql5="update b1 set points=-1 where tname='$s'";
$link->query($sql5);

$sql6="select tname from b1 where points=(select max(points) from b1)";
$res=$link->query($sql6);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',4)";
$link->query($a2);
$sql7="select tname from c1 where points=(select max(points) from c1)";
$res=$link->query($sql7);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',5)";
$link->query($a2);
$sql8="update c1 set points=-1 where tname='$s'";
$link->query($sql8);
$sql9="select tname from c1 where points=(select max(points) from c1)";
$res=$link->query($sql9);
$row=$res->fetch_assoc();
//$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',6)";
$link->query($a2);
$sql10="select tname from d1 where points=(select max(points) from d1)";
$res=$link->query($sql10);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',7)";
$link->query($a2);
$sql11="update d1 set points=-1 where tname='$s'";
$link->query($sql11);
$sql12="select tname from d1 where points=(select max(points) from d1)";
$res=$link->query($sql12);
$row=$res->fetch_assoc();
$s=$row["tname"];
$a2="insert into quarter_final values('$s',8)";
$link->query($a2);
	$_SESSION["val"]=0;
$_SESSION["op"]=1;
}
//ob_end_clean();
?>
</body>
</html>