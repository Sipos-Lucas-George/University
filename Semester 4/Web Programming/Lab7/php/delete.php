<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

global $conn;
require_once 'config.php';
$table_name = $_GET['table_name'];
$id = $_GET['id'];

$sql = "DELETE FROM $table_name WHERE id=$id";

if ($conn->query($sql) === TRUE) {
    echo json_encode("Data deleted successfully");
} else {
    echo json_encode("Error deleting record: " . $conn->error);
}