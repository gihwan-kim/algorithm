

### std::sort

- 오름차순으로 정렬
- 동일한 요소의 순서를 보장하지 않음


- 시간복잡도 : O(N*logN)


```
default (1)
			template <class RandomAccessIterator>
			void sort (RandomAccessIterator first, RandomAccessIterator last);
custom (2)
			template <class RandomAccessIterator, class Compare>
			void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

- firt, last : iterator 범위
- comp : 첫 번째 파라미터가 두번째 파라미터 보다 앞에 있을 경우 true 리턴

### std::stable_sort

- 오름차순으로 정렬
- 동일한 요소의 순서를 보장

- N log(N^2)