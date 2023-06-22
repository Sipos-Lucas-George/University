<?php
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

global $conn;
require_once 'config.php';
$table_name = $_GET['table_name'];
$filter = $_GET['filter'];
$key = $_GET['key'];
$offset = $_GET['offset'];
$limit = $_GET['limit'];

$sql = "SELECT * FROM $table_name";
if (!empty($filter)) {
    $sql .= " WHERE $key LIKE '%$filter%'";
}
$sql .= " LIMIT $offset, $limit;";
$result = $conn->query($sql);

$data = array();
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}
echo json_encode($data);
mysqli_close($conn);
