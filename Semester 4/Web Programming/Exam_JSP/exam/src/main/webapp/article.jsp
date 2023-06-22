<%@ page import="com.example.exam.Article" %>
<%@ page import="java.util.List" %>
<%@ page import="java.util.Objects" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.4/jquery.min.js"></script>
</head>
<body>
<form action="articles">
    <label>
        <input id="name" type="text" name="name" value="<%
        for (Cookie cookie : request.getCookies())
            if (Objects.equals(cookie.getName(), "user"))
                out.println(cookie.getValue());%>"
               readonly>
    </label>
    <label>
        <input id="journal" type="text" placeholder="journal" name="journal">
    </label>
    <button>View</button>
</form>
<p>
    <%
        List<Article> articles = (List<Article>) request.getSession().getAttribute("articles");
        for (Article article : articles) {
            out.println(article.toString());
        }
    %>
</p>
<div>
    <label>
        <input id="journal-id" type="text" placeholder="journal">
    </label>
    <button id="add-button">Add</button>
</div>
<form action="form-class" method="post">
    <label>
        <input id="variable" type="text" placeholder="variable" name="variable">
    </label>
    <label>
        <input id="x" type="text" placeholder="x" <%out.println(request.getParameter("newVar"));%> readonly>
    </label>
    <button>See what you don't see!</button>
</form>
</body>
<script src="article.js"></script>
</html>
