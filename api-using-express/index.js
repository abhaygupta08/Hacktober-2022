const PORT =process.env.port || 3000;
const express = require("express");
const bodyParser = require("body-parser");
const mongoose = require("mongoose");

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.set("view engine", "ejs");

mongoose.connect("mongodb://127.0.0.1:27017/topicDB");

const topicSchema = {
  heading: String,
  detail: String,
};

const Article = mongoose.model("article", topicSchema);

app
  .route("/articles")
  .get(function (req, res) {
    Article.find(function (err, foundArticles) {
      if (!err) {
        res.send(foundArticles);
      } else {
        res.send(err);
      }
    });
  })
  .post(function (req, res) {
    const newArticle = new Article({
      heading: req.body.heading,
      detail: req.body.detail,
    });
    newArticle.save(function (err) {
      if (!err) {
        res.send("New article has been added successfully.");
      } else {
        res.send(err);
      }
    });
  })
  .delete(function (req, res) {
    Article.deleteMany(function (err) {
      if (!err) {
        res.send("Successfully deleted all the item!");
      } else {
        res.send(err);
      }
    });
  });

app
  .route("/articles/:articleName")
  .get(function (req, res) {
    Article.findOne({ title: req.params.articleName }, function (err, foundItem) {
      if (!err) {
        res.send(foundItem);
      } else {
        res.send("No article found!");
      }
    });
  })
  .put(function (req, res) {
    Article.replaceOne(
      { heading: req.params.articleName },
      {
        heading: req.body.title,
        detail: req.body.content,
      },
      function (err) {
        if (!err) {
          res.send("successfully updated the article");
        }
      }
    );
  })
  .patch(function (req, res) {
    Article.updateOne(
      { heading: req.params.articleName },
      { $set: req.body },
      function (err) {
        if (!err) {
          res.send("Successfully updated the article");
        } else {
          res.send(err);
        }
      }
    );
  })
  .delete(function (req, res) {
    Article.deleteOne({ heading: req.params.articleName }, function (err) {
      if (!err) {
        res.send("Article has been deleted successfully");
      } else {
        res.send(err);
      }
    });
  });

app.listen(PORT, function () {
  console.log(`Server has been started on port ${PORT}` );
});