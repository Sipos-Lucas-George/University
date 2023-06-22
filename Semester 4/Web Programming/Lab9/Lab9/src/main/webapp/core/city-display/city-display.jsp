<%@ page import="java.util.List" %>
<%@ page import="domanin.City" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>City</title>
    <link rel="stylesheet" href="core/city-display/city-display.css">
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</head>
<body style="background: #212121;">
<form class="log-out-pos" action="logout">
    <button class="button1 type1">
        <span class="btn-txt">Log out</span>
    </button>
</form>
<div class="display-cities">
    <form id="destinations">
        <select id="destination0" onchange="addDestination(0)">
            <%
                List<City> cities = (List<City>) request.getSession().getAttribute("cities");
                out.println("<option value=\"-\">" + '-' + "</option>");
                for (City city : cities) {
                    out.println("<option value=\"" + (city.getId()) + "\">" + city.getName() + "</option>");
                }
            %>
        </select>
    </form>
</div>
<script src="core/city-display/city-display.js"></script>
</body>
</html>
