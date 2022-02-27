SELECT ANIMAL_ID, NAME,
    case when sex_upon_intake regexp 'neutered|spayed' then 'O' else 'X' end as 중성화
from animal_ins


-- case 조건 써서 칼럼 추가하기!