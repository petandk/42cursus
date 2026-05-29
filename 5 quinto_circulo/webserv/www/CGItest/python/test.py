#!/usr/bin/env python3
import os
import sys
import cgi
import cgitb
cgitb.enable()

method = os.environ.get("REQUEST_METHOD", "GET")

print("Content-Type: text/html\n")
print("<!DOCTYPE html>")
print("<html lang='en'>")
print("<head><meta charset='UTF-8'><title>Python CGI Test</title>")
print("<link rel='stylesheet' href='../css/style.css'>")
print("</head><body>")
print("<div class='container'>")
print("<h1>Python CGI Test</h1>")

if method == "POST":
    form = cgi.FieldStorage()
    name = form.getvalue("name", "Anonymous")
    message = form.getvalue("message", "")
    print(f"<p><strong>Method:</strong> POST</p>")
    print(f"<p><strong>Name:</strong> {name}</p>")
    print(f"<p><strong>Message:</strong> {message}</p>")
else:
    print(f"<p><strong>Method:</strong> GET</p>")
    print("<p>Send a POST request to see form data.</p>")

print("<h2>Environment Variables</h2>")
print("<ul>")
for key, value in sorted(os.environ.items()):
    print(f"<li><strong>{key}:</strong> {value}</li>")
print("</ul>")

print("<br><a class='home-link' href='../tools/python_form.php'>Back to Form</a>")
print("<br><a class='home-link' href='../index.php'>Return to Homepage</a>")
print("</div>")
print("</body></html>")
