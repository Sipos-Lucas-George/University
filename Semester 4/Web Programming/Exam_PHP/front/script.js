function redirect() {
    const user = $("#user").val();
    const father = $("#father").val();
    const mother = $("#mother").val();

    $.ajax({
        async: true,
        url: "http://localhost:1234/log.php",
        type: "GET",
        data: {user: user, father: father, mother: mother},
        dataType: "text",
        success: function (result) {
            if(result !== "\"fail\"") {
                document.cookie = "user=" + user;
                window.location="http://localhost:63342/Exam_PHP/front/display.html";
            }
        },
        error: function (err) {
            console.log(err);
        }
    })
}

function display() {
    const user = document.cookie.substring(document.cookie.indexOf("=") + 1);
    $.ajax({
        async: true,
        url: "http://localhost:1234/display.php",
        type: "GET",
        data: {user: user, father: "", mother: ""},
        dataType: "json",
        success: function (result) {
            if(result !== "fail") {
                $("#values").html(JSON.stringify(result));
            }
        },
        error: function (err) {
            console.log(err);
        }
    })
}

function addFun() {
    const user = $("#id").val();
    const father = $("#father").val();
    const mother = $("#mother").val();

    $.ajax({
        async: true,
        url: "http://localhost:1234/add.php",
        type: "POST",
        data: {user: user, father: father, mother: mother},
        dataType: "text",
        success: function (result) {
            console.log(result);
        },
        error: function (err) {
            console.log(err);
        }
    })
}

// let history = [];
// function submitClicked() {
//     const name1 = $("#name1").val();
//     const name2 = $("#name2").val();
//
//     if (!name1 && !name2)
//         alert("Enter at least 1 name");
//     else {
//         if (name1)
//             history.push(name1);
//         if (name2)
//             history.push(name2);
//         $.ajax({
//             async: true,
//             url: "http://localhost:1234/show.php",
//             type: "GET",
//             data: {name1: name1, name2: name2},
//             dataType: "json",
//             success: function (result) {
//                 $("#values").html(JSON.stringify(result));
//             },
//             error: function (err) {
//                 console.log(err.responseText);
//             }
//         })
//     }
// }
//
// function historyClicked() {
//     $("#history").html(JSON.stringify(history));
//     document.cookie = 'user=; ; Expires=Thu, 01 Jan 1970 00:00:01 GMT;';
//     location.reload();
// }
//
// function addCookie() {
//     const user = $("#user").val();
//     document.cookie = "user=" + user;
//     $.ajax({
//         async: true,
//         url: "http://localhost:1234/cookie.php",
//         type: "POST",
//         data: {user: user},
//         dataType: "text",
//         success: function (result) {
//             $("#cookie").val(document.cookie.substring(document.cookie.indexOf("=") + 1));
//             console.log("ok");
//         },
//         error: function (err) {
//             console.log(err);
//         }
//     })
// }
