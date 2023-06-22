let offset = 0;
let size;
$(function () {
    const tableName = "Reservation";
    const datatable = $("#data-table");

    function showTable() {
        $.ajax({
            async: true,
            url: "http://localhost:1234",
            type: "GET",
            data: {action: "select_data", table_name: tableName},
            dataType: "json",
            success: function (result) {
                size = result.length;
                datatable.empty();

                const header = "<thead><th>ID</th><th>Client ID</th><th>Room ID</th><th>Checkin</th><th>Checkout</th></thead>";
                datatable.append(header);

                for (let i = 0; i < 10; ++i) {
                    if (offset + i < size) {
                        const row = "<tr class=\"table_row\"><td>" + result[offset + i].id + "</td><td>" + result[offset + i].client_id + "</td><td>" + result[offset + i].room_id + "</td><td>" + result[offset + i].checkin + "</td><td>" + result[offset + i].checkout + "</td></tr>";
                        datatable.append(row);
                    }
                }

                let rows = document.querySelectorAll(".table_row");
                rows.forEach(function (item) {
                    item.addEventListener("click", function () {
                        document.getElementById("id-input").value = item.getElementsByTagName("td")[0].innerHTML;
                        document.getElementById("client-id-input").value = item.getElementsByTagName("td")[1].innerHTML;
                        document.getElementById("room-id-input").value = item.getElementsByTagName("td")[2].innerHTML;
                        document.getElementById("checkin-input").value = item.getElementsByTagName("td")[3].innerHTML;
                        document.getElementById("checkout-input").value = item.getElementsByTagName("td")[4].innerHTML;
                    });
                });
            },
            error: function () {
                console.log("Fail");
            }
        });
    }

    function clear() {
        let inputs = document.querySelectorAll("input");
        inputs.forEach(function (item) {
            item.value = "";
        });
    }

    showTable();

    // Insert data into the database
    $("#insert-button").on("click", function () {
        const client_id = $("#client-id-input");
        const room_id = $("#room-id-input");
        const checkin = $("#checkin-input");
        const checkout = $("#checkout-input");
        if (client_id.val() === "" || room_id.val() === "" || checkin.val() === "" || checkout.val() === "") {
            alert("Invalid input");
            return;
        }
        console.log(checkout.val());
        console.log(checkin.val());


        const data = {
            client_id: client_id.val(),
            room_id: room_id.val(),
            checkin: checkin.val(),
            checkout: checkout.val()
        };

        $.ajax({
            async: true,
            url: "http://localhost:1234",
            type: "POST",
            dataType: 'text',
            data: {action: "insert_data", table_name: tableName, data: data},
            success: function (result) {
                alert(result);
                showTable();
                clear();
            },
            error: function () {
                console.error("ERROR");
            }
        });
    });

    // Delete data from the database
    $("#delete-button").on("click", function () {
        const id = $("#id-input").val();
        if (id === "") {
            alert("No selected element");
            return;
        }

        $.ajax({
            async: true,
            url: "http://localhost:1234",
            type: "POST",
            data: {action: "delete_data", table_name: tableName, id: id},
            dataType: "text",
            success: function (result) {
                alert(result);
                showTable();
                clear();
            }
        });
    });

    // Update data in the database
    $("#update-button").on("click", function () {
        const client_id = $("#client-id-input");
        const room_id = $("#room-id-input");
        const checkin = $("#checkin-input");
        const checkout = $("#checkout-input");
        if (client_id.val() === "" || room_id.val() === "" || checkin.val() === "" || checkout.val() === "") {
            alert("Invalid input");
            return;
        }

        const id = $("#id-input").val();
        if (id === "") {
            alert("No selected element");
            return;
        }

        const data = {
            client_id: client_id.val(),
            room_id: room_id.val(),
            checkin: checkin.val(),
            checkout: checkout.val()
        };

        $.ajax({
            async: true,
            url: "http://localhost:1234",
            type: "POST",
            data: {action: "update_data", table_name: tableName, id: id, data: data},
            dataType: "text",
            success: function (result) {
                alert(result);
                showTable();
                clear();
            },
            error: function () {
                console.error("ERROR");
            }
        });
    });

    $("#clear-button").on("click", clear);
    $("#next-page").on("click", function () {
        if (offset + 10 < size) {
            offset += 10;
            showTable();
        }
    });
    $("#prev-page").on("click", function () {
        if (offset >= 10) {
            offset -= 10;
            showTable();
        }
    });
});
