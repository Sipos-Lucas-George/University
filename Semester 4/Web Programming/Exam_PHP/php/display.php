<?php

header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

global $conn;
require_once 'config.php';

$user = $_GET['user'];

$user_sql = "SELECT id FROM User WHERE username='$user'";

$result = $conn->query($user_sql);

$data = array();
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}

if (sizeof($data) == 0) {
    echo json_encode("fail");
    exit();
}

$id = implode($data[0]);

$family_sql = "SELECT mother FROM FamilyRelations WHERE userid=$id";
$result = $conn->query($family_sql);

$data = array();
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}
if (sizeof($data) == 0) {

    echo json_encode("good");
    exit();
}

$family_sql = "SELECT father FROM FamilyRelations WHERE userid=$id";
$result = $conn->query($family_sql);

$data1 = array();
while ($row = $result->fetch_assoc()) {
    $data1[] = $row;
}
if (sizeof($data1) == 0) {

    echo json_encode("good");
    exit();
}
$mother = implode($data[0]);
$father = implode($data1[0]);

$family_sql = "SELECT * FROM FamilyRelations WHERE userid!=$id AND (mother='$mother' OR father='$father')";
$result = $conn->query($family_sql);

$data = array();
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}

if (sizeof($data) > 0) {
    echo json_encode($data);
    exit();
}
echo json_encode("fail");