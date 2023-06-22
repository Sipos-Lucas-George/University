package controller;

import domanin.DB_Manager;
import domanin.User;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet(name = "entry", value = "/entry")
public class Login_Controller extends HttpServlet {
    public Login_Controller() {
        super();
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");

        String username = request.getParameter("username");
        String password = request.getParameter("password");

        if (username.equals("") || password.isEmpty()) {
            request.getSession().setAttribute("error", "Username/password must not be null!");
            request.getRequestDispatcher("entry.jsp").include(request, response);
        } else if (username.length() < 5 || password.length() < 5) {
            request.getSession().setAttribute("error", "Username/password not long enough!");
            request.getRequestDispatcher("entry.jsp").include(request, response);
        } else {
            DB_Manager dbManager = new DB_Manager();
            User user = dbManager.authenticate(username, password);
            if (user != null) {
                response.addCookie(new Cookie("user", user.getUsername()));
                response.sendRedirect("show-city");
            } else {
                request.getSession().setAttribute("error", "Username or password invalid!");
                request.getRequestDispatcher("entry.jsp").include(request, response);
            }
        }
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        request.getRequestDispatcher("entry/entry.jsp").include(request, response);
    }
}
