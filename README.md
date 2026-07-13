# Geometry Playground

### 컴퓨터비전에서 사용하는 모든 기하학을 직접 구현해보기
<img width="776" height="535" alt="image" src="https://github.com/user-attachments/assets/b03a58dd-67bf-440d-8a66-4e857586474d" />

Eigen3.4.1 설치 필요
pch.h : `using namespace std;` , `C++ SLT` , `Eigen 헤더'
헤더(.h): using namespace 사용하지 않음. pch.h 넣지 않고 필요한것만 넣음
소스(.cpp): using namespace geometry; 사용.
Demo 및 테스트 코드: `using namespace geometry;`와 `using namespace Eigen;` 사용.



```
GeometryPlayground
│
├── Geometry.Core
│      Matrix
│      Vector
│      Rotation
│
├── Geometry.Camera
│      Projection
│      Calibration
│
├── Geometry.Demo
│      실행 프로그램
│
├── Geometry.Test
│      테스트
│
└── ThirdParty
        Eigen
```

<br>
<br>

---

<br>
<br>


## C++ Geometry and Camera Calibration Toolkit


#### 1단계: Geometry Playground

가장 먼저 구현할 프로젝트입니다.
```
geometry/
├─ Transform2D
├─ Transform3D
├─ RotationMatrix
├─ EulerAngles
├─ Rodrigues
├─ Quaternion
├─ Homography
├─ Projection
├─ Triangulation
└─ RANSAC
```


#### 2단계: Camera Calibration Toolkit

Geometry 모듈 위에 캘리브레이션을 구현합니다.
```
calibration/
├─ ChessboardDetector
├─ HomographyEstimator
├─ ZhangInitializer
├─ DistortionModel
├─ ReprojectionError
├─ CameraPoseEstimator
└─ CalibrationOptimizer
```
구현 순서는 다음이 좋습니다.

  1. 체스보드 코너 검출
  2. Subpixel refinement
  3. 영상별 Homography 계산
  4. Zhang 방법으로 내부 파라미터 초기화
  5. 외부 파라미터 복원
  6. 왜곡계수 추정
  7. Reprojection error 계산
  8. 비선형 최적화
  9. cv::calibrateCamera()와 비교

최적화는 처음에는 직접 Gauss-Newton을 구현하고, 이후 Ceres Solver를 붙이는 방식이 좋습니다.

#### 3단계: Photometric Stereo

앞의 수학 모듈을 활용해 표면 법선을 복원합니다.
```
photometric/
├─ LightCalibrator
├─ LambertianSolver
├─ NormalEstimator
├─ AlbedoEstimator
├─ ShadowMask
├─ DepthIntegrator
└─ MeshExporter
```
기본 모델은 픽셀별로 다음 선형식을 풉니다.
$i = Lg,\quad g = \rho n$

초기 버전에서는 다음 조건만 다루면 됩니다.

고정된 카메라
알려진 평행광 방향
Lambertian 표면
흑백 이미지
그림자와 포화 영역 제외

이후 확장합니다.

Robust least squares
Shadow detection
Specular rejection
Unknown light estimation
Poisson depth integration
OBJ mesh export

