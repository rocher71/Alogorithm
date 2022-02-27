-- 복습 필수, 검색했음


select ANIMAL_OUTS.ANIMAL_ID, ANIMAL_OUTS.NAME
from animal_outs
inner join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
order by animal_outs.datetime-animal_ins.datetime desc LIMIT 2


-- datediff 로 새로운 col 만들어서 순서대로 정렬해서 출력하려 했었는데 datediff에서 계속 오류뜸 - >검색
-- order by 에서 날짜 - 로 빼고 출력하니까 됐음.