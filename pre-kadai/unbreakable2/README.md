unbreakable cipher 2 (Reversing, Crypto; 50 pts.)
====

> This task checks your basic reversing and cryptograph skills.

No, no! My cipher has broken! So I revised it.
Can u still break it? 
Flag format is `flag{****}`

```bash
% echo -n "angr is awesome" | ./unbreakable2 $(cat vivi) | xxd
00000000: cddc ae56 b12d 6168 40f0 7a0f 9eab 7f    ...V.-ah@.z....
% ./unbreakable2 $(cat vivi) < flag > encrypted_flag
```

attached files: [unbreakable2](./unbreakable2), [encrypted_flag](./encrypted_flag)
