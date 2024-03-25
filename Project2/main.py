from fastapi import FastAPI, Request, HTTPException
from fastapi.responses import HTMLResponse, RedirectResponse
from fastapi.templating import Jinja2Templates
from bidding_classes import SuiteHandler, DeluxeHandler, StandardHandler
from pydantic import BaseModel

class Bid(BaseModel):
    bid_price: float

app = FastAPI()
templates = Jinja2Templates(directory="templates")

suite_handler = SuiteHandler()
deluxe_handler = DeluxeHandler()
standard_handler = StandardHandler()

suite_handler.set_successor(deluxe_handler)
deluxe_handler.set_successor(standard_handler)

@app.get("/", response_class=HTMLResponse)
def read_root(request: Request):
    return templates.TemplateResponse("bid.html", {"request": request})

@app.post("/bid")
def make_bid(bid: Bid):
    message = suite_handler.handle_request(bid.bid_price)
    redirect_url = f"/message?message={message}"
    return RedirectResponse(url=redirect_url)

@app.get("/message", response_class=HTMLResponse)
def show_message(request: Request, message: str):
    return templates.TemplateResponse("message.html", {"request": request, "message": message})