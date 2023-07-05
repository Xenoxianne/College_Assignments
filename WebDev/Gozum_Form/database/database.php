<?php
    $serverName = 'localhost';
    $userName = 'root';
    $password = '';
    $dbName = 'maindb';

    $connection = mysqli_connect($serverName, $userName, $password, $dbName) or die('connection failed');
    
    if (!$connection) {
        echo "Connection failed!";
    }
?>