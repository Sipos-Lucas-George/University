package com.example.exam;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.util.List;
import java.util.Objects;

@WebServlet(name = "articles", value = "/articles")
public class Articles extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html");
        String journal = request.getParameter("journal");
        String name = "";
        for (Cookie cookie : request.getCookies())
            if (Objects.equals(cookie.getName(), "user"))
                name = cookie.getValue();
        List<Article> articles = new DB_Manager().getArticlesFromJournal(name, journal);
        request.getSession().setAttribute("articles", articles);
        request.getRequestDispatcher("article.jsp").forward(request, response);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String name = request.getParameter("name");
        response.addCookie(new Cookie("user", name));
        response.sendRedirect("articles");
    }
}