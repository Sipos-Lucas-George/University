$("#add-button").on("click", function () {
    const name = $("#name").val();
    const journal = $("#journal-id").val();

    $.ajax({
        async: true,
        url: "add-article",
        type: "POST",
        data: {name: name, journal: journal},
        dataType: "text",
        success: function (err){
            console.log(err);
        },
        error: function (err) {
            console.log(err);
        }
    });
});