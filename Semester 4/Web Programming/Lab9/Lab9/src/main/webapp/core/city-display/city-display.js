function addDestination(select_id) {
    let selected_city_option = $("#destination" + select_id)[0];
    let selected_city = selected_city_option.options[selected_city_option.selectedIndex];
    let destinations = $("#destinations");
    destinations.children("select").each(function () {
        let id = parseInt(this.id.substring(11));
        if (select_id < id)
            $(this).remove();
    })
    if (selected_city.value === "-")
        return;
    $.ajax({
        async: true,
        url: 'show-neighbour',
        method: 'GET',
        data: {id: parseInt(selected_city.value)},
        success: function (response) {
            let new_select = document.createElement("select");
            new_select.id = "destination" + (select_id + 1);
            new_select.setAttribute("onchange", "addDestination(" + (select_id + 1) + ")");
            new_select.setAttribute("class", "custom-select");
            let redundant = document.createElement("option");
            redundant.value = "-";
            redundant.text = "-";
            new_select.appendChild(redundant);
            response.forEach(function (city) {
                let option = document.createElement("option");
                option.value = city.id;
                option.text = city.name;
                new_select.appendChild(option)
            })
            destinations.append(new_select);
        },
        error: function (response) {
            alert(response.responseText);
        }
    })
}
