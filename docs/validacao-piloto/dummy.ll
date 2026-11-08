; ModuleID = 'docs/validacao-piloto/dummy.rob'
source_filename = "docs/validacao-piloto/dummy.rob"
target datalayout = "e-m:e-p:32:32-Fi8-i64:64-v128:64:128-a:0:32-n32-S64"
target triple = "thumbv7m-none-eabi"

define linkonce_odr zeroext i8 @typeid(ptr readonly %0) #0 {
  %2 = icmp eq ptr %0, null
  br i1 %2, label %3, label %4

3:                                                ; preds = %1
  ret i8 0

4:                                                ; preds = %1
  %5 = load i8, ptr %0, align 1
  ret i8 %5
}

; Function Attrs: noinline
define void @initialise_benchmark() #1 {
body:
  ret void
}

; Function Attrs: noinline
define void @warm_caches(i32 %heat) #1 {
  %heat1 = alloca i32, align 4
  store i32 %heat, ptr %heat1, align 4
  br label %body

body:                                             ; preds = %0
  ret void
}

; Function Attrs: noinline
define i32 @benchmark() #1 {
body:
  ret i32 190
}

; Function Attrs: noinline
define i32 @verify_benchmark(i32 %r) #1 {
  %r1 = alloca i32, align 4
  store i32 %r, ptr %r1, align 4
  br label %body

body:                                             ; preds = %0
  %r2 = load i32, ptr %r1, align 4
  %cmpi = icmp eq i32 %r2, 190
  %zext = zext i1 %cmpi to i32
  ret i32 %zext
}

attributes #0 = { "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }
attributes #1 = { noinline "frame-pointer"="all" "stack-protector-buffer-size"="8" "target-cpu"="cortex-m3" }

!llvm.module.flags = !{!0}

!0 = !{i32 7, !"frame-pointer", i32 2}
