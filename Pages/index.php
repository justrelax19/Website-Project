<?php
session_start();
if(!isset($_SESSION["status"]))
	header("Location:../Login/login1.php");
?>
<!doctype html>
<html>
  <head>
	<meta charset="utf-8">
	<link rel="stylesheet" type="text/css" href="main.css">
	<link rel='stylesheet' href='styles2.css'>
	<title>Home</title>
  </head>

<body>
	<div id="allcontent">
	<video  id="bgvid" autoplay loop muted>
    <source src="../videos/v3.mp4" type="video/mp4">
	</video>
	
	<div id="header">
		<a href="index.php"  > <span class ="header_logo"> <img src="../Images/League.jpg" title="Home" height="70" width='70' ></span></a> 
		<a href="../teams/argentinea.php"> <span class ="header_img"> <img src="../Images/arg.gif" title="Argentina" height="30" width='30'></span></a>
		<a href="../teams/belgium.php"  > <span class ="header_img"> <img src="../Images/bel.gif"  title="Belgium" height="30" width="30"></span></a>
		<a href="../teams/brasil.php"> <span class ="header_img"> <img src="../Images/bra.gif"  title="Brazil" height="30" width="30" ></span></a>
		<a href="../teams/chile.php"> <span class ="header_img"> <img src="../Images/chi.gif"  title="Chile" height="30" width="30" ></span></a>
		<a href="../teams/republic.php"  > <span class ="header_img"> <img src="../Images/cze.gif"  title="Czech Republic" height="30" width="30" ></span></a>
		<a href="../teams/denmark.php"  > <span class ="header_img"> <img src="../Images/den.gif"  title="Denmark" height="30" width="30" ></span></a>
		<a href="../teams/england.php"  > <span class ="header_img"> <img src="../Images/eng.gif"  title="England" height="30" width="30" ></span></a>
		<a href="../teams/france.php"  > <span class ="header_img"> <img src="../Images/fra.gif"  title="France" height="30" width="30" ></span></a>
		<a href="../teams/germany.php"  > <span class ="header_img"> <img src="../Images/ger.gif"  title="Germany" height="30" width="30" ></span></a>
		<a href="../teams/italy.php"  > <span class ="header_img"> <img src="../Images/ita.gif"  title="Italy" height="30" width="30" ></span></a>
		<a href="../teams/netherlands.php"  > <span class ="header_img"> <img src="../Images/ned.gif"  title="Netherlands" height="30" width="30" ></span></a>
		<a href="../teams/poland.php"  > <span class ="header_img"> <img src="../Images/pol.gif"  title="Poland" height="30" width="30" ></span></a>
		<a href="../teams/portugal.php"  > <span class ="header_img"> <img src="../Images/por.gif"  title="Portugal" height="30" width="30" ></span></a>
		<a href="../teams/spain.php"> <span class ="header_img"> <img src="../Images/esp.gif"  title="Spain" height="30" width="30" ></span></a>
		<a href="../teams/sewden.php"  > <span class ="header_img"> <img src="../Images/swe.gif"  title="Sweden" height="30" width="30" ></span></a>
		<a href="../teams/uruguay.php"  > <span class ="header_img"> <img src="../Images/uru.gif"  title="Uruguay" height="30" width="30" ></span></a><br>
	</div>		
		<div id='cssmenu'>
			<ul>
			   <li><a href='index.php'><span>HOME</span></a></li>
			   <li class='active has-sub'><a href='#'><span>TEAMS</span></a>
				  <ul>
						<div id="dropdown">
							<div id="tablecontainer">	
								<div id="tablerow">
									<div id="ga">
									<h2 id="ddt">GROUP A</h2>
										<ol>
											
											<li><a href="../teams/argentinea.php">Argentina</a></li>
											<li><a href="../teams/brasil.php">Brazil</a></li>
											<li><a href="../teams/denmark.php">Denmark</a></li>
											<li><a href="../teams/france.php"> France</a></li>
										</ol>
									</div>
									<div id="gb">		
									<h2 id="ddt">GROUP B</h2>
										<ol>
											<li><a href="../teams/netherlands.php">Netherlands</a></li>
											<li><a href="../teams/portugal.php"  > Portugal</a></li>
											<li><a href="../teams/spain.php"  > Spain</a></li>
											<li><a href="../teams/uruguay.php"  > Uruguay</a></li>
										</ol>
									</div>
									<div id="gc">	
									<h2 id="ddt">GROUP C</h2>
										<ol>
											<li><a href="../teams/belgium.php"  > Belgium</a></li>
											<li><a href="../teams/chile.php"  > Chile</a></li>
											<li><a href="../teams/czech.php"  > Czech Republic</a></li>
											<li><a href="../teams/england.php"  > England</a></li>
										</ol>
									</div>
									<div id="gd">	
									<h2 id="ddt">GROUP D</h2>
										<ol>
											<li><a href="../teams/germany.php"  >Germany</a></li>
											<li><a href="../teams/italy.php"  >Italy</a></li>
											<li><a href="../teams/poland.php"  >Poland</a></li>
											<li><a href="../teams/sweden.php"  >Sweden</a></li>
										</ol>
									</div>	
									</div>
							</div>	
						</div>
					 
					 
					
				  </ul>
			   </li>
			   <li class='active has-sub'><a href='#'><span>PLAYERS</span></a>
			   <ul>
					<div id="dropdown">
							<div id="tablecontainer">	
								<div id="tablerow">
									<div id="pinklinks">
									
										<ol>
											<li>GROUP A</li><br>
											<li>GROUP B</li><br>
											<li>GROUP C</li><br>
											<li>GROUP D</li><br>
										</ol>
									</div>
									<div id="featured">		
									<h2 id="ddt2" >FEATURED</h2>
										<img src="../images/messi.jpg"/><!--Put a photo of messi here -->
									</div>
									<div id="recent">	
									<h2 id="ddt2">RECENT</h2>
										<ol>
											<li>Lionel Messi</li>
											<li>Christiano Ronaldo</li>
											<li>Neymar</li>
										</ol>
									</div>
									
									</div>
							</div>	
						</div>
					 
				</ul>
			   </li>
			   <li class='active has-sub'><a href='#'><span>NEWS</span></a>
			   <ul>
					<div id="dropdown">
							<div id="tablecontainer">	
								<div id="tablerow">
									
									<div id="featured2">		
									<h2 id="ddt3" >FEATURED</h2>
										<li>No new updates</li>
									</div>
									<div id="recent">	
									<h2 id="ddt3">RECENT</h2>
										<li>No new updates</li>
										
										
									</div>
									<div id="recent2">	
									
										
										
										
									</div>
									
								</div>
							</div>	
						</div>
					 
				</ul>
			   </li>
			   <li class='active has-sub'><a href='#'><span>ABOUT</span></a>
			   <ul>
					<div id="dropdown">
							<div id="tablecontainer">	
								<div id="tablerow">
									
									<div id="wwd">		
										<h2 id="ddt4" >WHAT WE DO</h2> 
										<a href="wwd.htm"><img width="300" height=auto src="../Images/wwd.png"></a>
									</div>
									
									<div id="wwr">	
										<h2 id="ddt4">WHO WE ARE</h2>
										<a href="wwr.htm"><img width="300" height=auto src="../Images/back/image_1.jpg"></a>
										
									</div>
									
									<div id="fr">	
										<h2 id="ddt5" >FORMAL RELATIONS</h2>
										<p>UEFA
											UEFA (Union of European Football Associations) is a competition organiser 
											and is responsible for the organisation and regulation of cross-border football in Europe. 
											It also organises the European Championships for national associations every four years.</p>
										<a href="fe.htm">Read More...</a>	
																	
									</div>
									
								</div>
							</div>	
						</div>
					 
				</ul>
			   </li>
   
  
  <li><a href="../Login/login1.php">Sign In</a></li>
 
   
</ul>

</div>
			<br>
			<a href="../login/login1.php" id="tgifLogo"><span id="tgif_image"><img src="../Images/img4.jpg" title="CLICK for Fantasy League" alt='TGIF logo'></span></a>
			<div id="bottom">
				<p>	
				
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					
				</p>
			</div>
	
	<div id="footer">
		<p>
			<a href="sitemap.htm">Site map</a>
		</p>
	</div>
</div>	
</body>


</php>