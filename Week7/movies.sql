SELECT title FROM movies WHERE year = 2008;
SELECT birth FROM people WHERE name = "Emma Stone";
SELECT title FROM movies WHERE year > 2017 ORDER BY title;
SELECT COUNT(*) FROM ratings WHERE rating = 10.0;
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;

SELECT AVG(rating) FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2012;

SELECT title, rating FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title ASC;

SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id in (SELECT id FROM movies WHERE title = "Toy Story"));

SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth;

SELECT DISTINCT name FROM people
JOIN directors ON people.id = directors.person_id
JOIN movies ON movies.id = directors.movie_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0;

SELECT title FROM movies
JOIN ratings ON movies.id = ratings.movie_id
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;

SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Bradley Cooper"
AND title IN
(SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Jennifer Lawrence");

SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN
(SELECT movies.id FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
AND people.name != "Kevin Bacon";