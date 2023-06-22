package com.example.exam;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet(name = "addArticle", value = "/add-article")
public class AddArticle extends HttpServlet {
    private String name;

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.name = req.getParameter("name");
        int journal = Integer.parseInt(req.getParameter("journal"));
        new DB_Manager().addArticles(name, journal);
    }
}
