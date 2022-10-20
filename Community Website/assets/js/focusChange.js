window.onload = function () {
  var preTitle = document.title;
  var postTitle = "Gone too soon ! 🥺";
  document.addEventListener("visibilitychange", function () {
    var page_Active = !document.hidden;

    if (!page_Active) {
      document.title = postTitle;
    } else {
      document.title = preTitle;
    }
  });
};
