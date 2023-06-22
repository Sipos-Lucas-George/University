<?php

header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type, Authorization");

global $conn;
require_once 'config.php';

$user = $_GET['user'];
$mother = $_GET['mother'];
$father = $_GET['father'];

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

$family_sql = "SELECT * FROM FamilyRelations WHERE userid=$id AND (mother='$mother' OR father='$father')";
$result = $conn->query($family_sql);

$data = array();
while ($row = $result->fetch_assoc()) {
    $data[] = $row;
}

if (sizeof($data) > 0) {

    echo json_encode("good");
    exit();
}
echo json_encode("fail");

//if (empty($name1)) {
//    $name1 = $name2;
//    $name2 = null;
//}
//if (empty($name2)) {
//    $sql = "SELECT id FROM Person WHERE name_surname='$name1'";
//    $result = $conn->query($sql);
//
//    $data = array();
//    while ($row = $result->fetch_assoc()) {
//        $data[] = $row;
//    }
//
//    $id = implode($data[0]);
//    $book_sql = "SELECT * FROM Book where id_author=$id";
//    $article_sql = "SELECT * FROM Article where id_author=$id";
//
//    $result = $conn->query($book_sql);
//    $data1 = array();
//    while ($row1 = $result->fetch_assoc()) {
//        $data1[] = $row1;
//    }
//
//    $result = $conn->query($article_sql);
//    $data2 = array();
//    while ($row2 = $result->fetch_assoc()) {
//        $data2[] = $row2;
//    }
//
//    if (sizeof($data1) > sizeof($data2)) {
//        echo json_encode($data1);
//    } else {
//        echo json_encode($data2);
//    }
//} else {
//    $sq1 = "SELECT id FROM Person WHERE name_surname='$name1'";
//    $result = $conn->query($sq1);
//
//    $data1 = array();
//    while ($row = $result->fetch_assoc()) {
//        $data1[] = $row;
//    }
//
//    $sq2 = "SELECT id FROM Person WHERE name_surname='$name2'";
//    $result = $conn->query($sq2);
//
//    $data2 = array();
//    while ($row = $result->fetch_assoc()) {
//        $data2[] = $row;
//    }
//
//    $id1 = implode($data1[0]);
//    $id2 = implode($data2[0]);
//
//
//    $book_sql1 = "SELECT * FROM Book where id_author=$id1";
//    $article_sql1 = "SELECT * FROM Article where id_author=$id1";
//
//    $book_sql2 = "SELECT * FROM Book where id_author=$id2";
//    $article_sql2 = "SELECT * FROM Article where id_author=$id2";
//
//    $result = $conn->query($book_sql1);
//    $data1_1 = array();
//    while ($row1 = $result->fetch_assoc()) {
//        $data1_1[] = $row1;
//    }
//
//    $result = $conn->query($article_sql1);
//    $data1_2 = array();
//    while ($row2 = $result->fetch_assoc()) {
//        $data1_2[] = $row2;
//    }
//
//    $result = $conn->query($book_sql2);
//    $data2_1 = array();
//    while ($row1 = $result->fetch_assoc()) {
//        $data2_1[] = $row1;
//    }
//
//    $result = $conn->query($article_sql2);
//    $data2_2 = array();
//    while ($row2 = $result->fetch_assoc()) {
//        $data2_2[] = $row2;
//    }
//
//    if (sizeof($data1_1) + sizeof($data1_2) > sizeof($data2_1) + sizeof($data2_2)) {
//        echo json_encode(array_merge($data1_1, $data1_2));
//    } else {
//        echo json_encode(array_merge($data2_1, $data2_2));
//    }
//}
mysqli_close($conn);
