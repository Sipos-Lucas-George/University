<?php

header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

global $conn;
require_once 'config.php';

$user = $_POST['user'];
$mother = $_POST['mother'];
$father = $_POST['father'];

$user_sql = "SELECT id FROM User WHERE id=$user";

$result = $conn->query($user_sql);

$data = array();
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}

if (sizeof($data) == 0) {
    echo json_encode("fail");
    exit();
}

$family_sql = "insert into FamilyRelations (userid, mother, father) values ($user, '$mother', '$father')";
$result = $conn->query($family_sql);

echo json_encode("good");