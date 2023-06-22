<?php

header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type, Authorization");


$user = $_POST["user"];

$cookieName = "user";
$cookieExpiration = time() + 360000000;
$cookiePath = "/";
setcookie($cookieName, $user);//, $cookieExpiration, $cookiePath);

http_response_code(200);
