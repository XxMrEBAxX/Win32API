#pragma once

#define SINGLE(type) public: static type* GetInst() \
						{ \
							static type inst; \
							return &inst; \
						}\
						private: type(); \
						~type();

#define fDT CTimeMgr::GetInst()->GetfDT()
#define DT CTimeMgr::GetInst()->GetDT()