SELECT name FROM people
JOIN stars on stars.person_id = people.id
JOIN movies on movies.id = stars.movie_id
WHERE title = "Toy Story";
