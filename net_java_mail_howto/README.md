# How to install Java Mail in Max on Mac OS


Download the file ```javax.mail.jar``` from the following page:

* [https://java.net/projects/javamail/pages/Home](https://java.net/projects/javamail/pages/Home)

Drop the downloaded file into the following directory:
```
/Applications/Max.app/Contents/Resources/C74/packages/max-mxj/java-classes/lib
```

Add the following object to a max patch:

```
|mxj net.mail.send]
```

Click the object with the alt-key pressed to see the help file.