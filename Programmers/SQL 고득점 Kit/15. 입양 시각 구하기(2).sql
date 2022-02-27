-- 방법 1

SET @hour := -1;

SELECT (@hour := @hour + 1) as HOUR,
    (SELECT COUNT (*) FROM ANIMAL_OUTS 
    WHERE HOUR(DATETIME) = @hour) as COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23


-- 방법 2

set @hour = -1;

select (@hour := @hour + 1 ) as hour,
    (select count(hour(datetime))
    from animal_outs
    where hour(datetime) = @hour) as COUNT
from animal_outs
where @hour < 23

-- 연습 
-- select 뒤에 괄호 안써도 됨, where는 꼭 from 뒤에 쓰기. select -> from -> where
set @hour = -1;

select @hour := @hour +1 as HOUR,
    (select count(hour(datetime))
    from animal_outs
    where hour(datetime) = @hour) as COUNT
from animal_outs
where @hour < 23