$(function () {
    const tableName = "Client";
    const datatable = $("#data-table");
    function showTable() {
        $.ajax({
            async: true,
            url: "http://localhost:1234",
            type: "GET",
            data: {action: "select_data", table_name: tableName},
            dataType: "json",
            success: function (result) {
                datatable.empty();

                const header = "<thead><th>ID</th><th>Name</th><th>Telephone</th></thead>";
                datatable.append(header);

                result.forEach(function (item) {
                    const row = "<tr class=\"table_row\"><td>" + item.id + "</td><td>" + item.full_name + "</td><td>" + item.telephone + "</td></tr>";
                    datatable.append(row);
                });

                let rows = document.querySelectorAll(".table_row");
                rows.forEach(function (item) {
                    item.addEventListener("click", function () {
                        document.getElementById("id-input").value = item.getElementsByTagName("td")[0].innerHTML;
                        document.getElementById("name-input").value = item.getElementsByTagName("td")[1].innerHTML;
                        document.getElementById("tel-input").value = item.getElementsByTagName("td")[2].innerHTML;
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
        const name = $("#name-input");
        const telephone = $("#tel-input");
        if (name.val() === "" || telephone.val() === "") {
            alert("Invalid input");
            return;
        }

        const data = {
            full_name: name.val(),
            telephone: telephone.val()
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
        const name = $("#name-input");
        const telephone = $("#tel-input");
        if (name.val() === "" || telephone.val() === "") {
            alert("Invalid input");
            return;
        }

        const id = $("#id-input").val();
        if (id === "") {
            alert("No selected element");
            return;
        }

        const data = {
            full_name: name.val(),
            telephone: telephone.val()
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
});
