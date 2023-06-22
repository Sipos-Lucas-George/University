<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS, PATCH");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

if ($_SERVER['REQUEST_METHOD'] === 'OPTIONS') {
    http_response_code(200);
    exit;
}
global $conn;
require_once 'config.php';

$json = json_decode(file_get_contents('php://input'));
$table_name = $json->table_name;
$id = $json->id;
$data = (array) $json->data;

$values = "";
foreach ($data as $key => $value) {
    $values .= "$key='$value', ";
}
$values = rtrim($values, ", ");
$sql = "UPDATE $table_name SET $values WHERE id=$id";

if ($conn->query($sql) === TRUE) {
    echo json_encode("Data updated successfully");
} else {
    echo json_encode("Error updating record: " . $conn->error);
}
