<?php
    session_start();

    if (isset($_SESSION['user'])) { 
?>
<!DOCTYPE html>

<html>
    <head>
		<meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE-edge" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Aerith | Home</title>
        <link rel="icon" href="../img/Logo.png" type="image/x-icon"/>
        <link href="../css/index.css" rel="stylesheet"/>
        <style>
            body {
                background-image: linear-gradient(rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.5)), url(../img/background.jpg);
            }
        </style>
	</head>

    <body>
        <div class = "content">
            <h1 style="font-size: 30px">aerith.</h1>
            <br/>
            <h1>Hello!</h1>
            <br/>

            <a href = "logout.php" class="btn">Logout</a>
        </div>
    </body>
</html>

<?php 
    } else{
        header("Location: ../index.php");
        exit();
    }
?>