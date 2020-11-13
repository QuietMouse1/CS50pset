SELECT title 
FROM movies JOIN ratings ON movies.id=ratings.movie_id 
JOIN stars ON stars.movie_id=ratings.movie_id
JOIN people on stars.person_id=people.id
WHERE name = "Chadwick Boseman" 
ORDER BY rating DESC 
LIMIT 5